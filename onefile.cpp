#include <iostream>
#include <string>
#include <cstring>
#include <cmath> // abs ve fabs için

#define CUINT const unsigned int
#define UINT unsigned int

using namespace std;

namespace TRIW {
    // 3 Bit Header (En sol 3 bit)
    // 29 Bit Payload
    CUINT SHIFTOP = 0x1FFFFFFF; // Payload maskesi (Alttaki 29 bit)
    CUINT MWCMP = 0xE0000000; // Header maskesi (Üstteki 3 bit)

    // Header tanımları (Üst 3 bite yerleştirilmiş halleri)
    CUINT MW1 = 0x20000000; // 0010 ...
    CUINT MW2 = 0x40000000; // 0100 ...
    CUINT MW3 = 0x80000000; // 1000 ...

    class TRIFLOAT32 {
    public:
        UINT number;

        // Statik oluşturucu
        static TRIFLOAT32 Sign(UINT SignType, float _number = 1) {
            TRIFLOAT32 result(_number); // Önce float'ı işle
            result.setSign(SignType);   // Sonra header'ı bas
            return result;
        }

        // Constructor
        TRIFLOAT32(float f = 0) {
            // 1. Daima pozitif sakla (İşaret W1/W2/W3 ile yönetiliyor)
            f = fabs(f);

            uint32_t bits;
            memcpy(&bits, &f, 4);

            // 2. Float verisini 3 bit sağa kaydır (Son 3 bit hassasiyet kaybı olur)
            // Not: Float pozitif olduğu için en sol bit zaten 0'dı, kaydırınca sorun olmaz.
            UINT compressedPayload = (bits >> 3) & SHIFTOP;

            // 3. Varsayılan olarak MW1 ile birleştir
            number = compressedPayload | MW1;
        }

        // Float'a geri dönüş operatörü
        operator float() const {
            // 1. Payload'ı ayıkla ve eski yerine (sola 3 birim) kaydır
            uint32_t bits = (number & SHIFTOP) << 3;

            // Not: Orijinal float'ın son 3 biti "000" oldu. 
            // İşaret biti (En sol bit) zaten 0, çünkü pozitif sakladık.

            float f;
            memcpy(&f, &bits, 4);
            return f;
        }

        operator string() {
            float f = *this;
            UINT header = getSign();
            string signStr = (header == MW1) ? "(W1)" :
                (header == MW2) ? "(W2)" :
                (header == MW3) ? "(W3)" : "(?)";
            return to_string(f) + signStr; // Örnek: 5.6000(W2)
        }

        // Header okuma
        UINT getSign() const {
            return number & MWCMP;
        }

        // Header yazma
        void setSign(UINT signMask) {
            UINT payload = number & SHIFTOP;
            UINT newHeader = signMask & MWCMP;
            number = payload | newHeader;
        }

        // Çarpma işlemi
        TRIFLOAT32 operator*(TRIFLOAT32 _tf) {
            float valA = *this;
            float valB = _tf;

            // Headerları al
            UINT h1 = this->getSign();
            UINT h2 = _tf.getSign();

            // Değerleri çarp
            TRIFLOAT32 result(valA * valB);

            // Header mantığı (W1, W2, W3 cebiri)
            if (h1 == MW1) {
                result.setSign(h2);
            }
            else if (h2 == MW1) {
                result.setSign(h1);
            }
            else if (h2 == MW2 && h1 == MW2) {
                result.setSign(MW3);
            }
            else if (h1 == MW3 && h2 == MW3) {
                result.setSign(MW2);
            }
            else if ((h1 == MW2 && h2 == MW3) || (h1 == MW3 && h2 == MW2)) {
                result.setSign(MW1);
            }

            return result;
        }

        // 1/x One over self
        TRIFLOAT32 OOS() {
            TRIFLOAT32 x = Sign(getSign());
            return Sign( (x*x).getSign(), 1 / (operator float()));
        }

        TRIFLOAT32 operator / (TRIFLOAT32 _f) {
            return operator*(_f.OOS()); 
        }

        TRIFLOAT32 V1(TRIFLOAT32 _f) {
            TRIFLOAT32 result;
            if (_f.getSign() == getSign()) {
                float sum = (float)_f + (float)*this;
                result = TRIFLOAT32(sum);
                result.setSign(getSign());
            }
            else {
                float diff = (float)_f - (float)*this;
                result = TRIFLOAT32(diff);
                result.setSign(diff > 0 ? _f.getSign() : getSign());
            }
            return result;
        }

        TRIFLOAT32 V3(TRIFLOAT32 _f) {
            TRIFLOAT32 temp = _f * TRIFLOAT32::Sign(MW3, 1.0f);
            return V1(temp);
        }

        static TRIFLOAT32 W1pow(TRIFLOAT32 x, TRIFLOAT32 y) {
            x.setSign(MW1);
            if (y.getSign() == MW1) {
                return (powf(x.operator float(), y.operator float()));
            };


            TRIFLOAT32 result = 1/(powf(x.operator float(), y.operator float()));
            TRIFLOAT32 sgnedy = Sign(y.getSign());
            result.setSign((sgnedy * sgnedy).getSign());
            return result;
        }
    };
}

using namespace TRIW;
#define TRIFLOAT32 TF32

int main() {

    

    return 0;
}
