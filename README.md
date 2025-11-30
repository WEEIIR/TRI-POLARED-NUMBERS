## 🧮 V-Operatör Sistemi (V-System Mechanics)

TRIW sisteminde skaler toplama (+) veya çıkarma (-) operatörleri yoktur. Bunun yerine, operandların "Durumlarını" (W1/W2/W3) işleyen ve karşılaştıran üç adet V-Operatörü bulunur.

Bu operatörler, standart matematikteki "işaret değiştirme" ($5 - 3 \rightarrow 5 + (-3)$) mantığının, üçlü sistemdeki karşılığıdır.

### 1. Temel Etkileşim Operatörü: V1 (Base Merge)
V1, sistemin "Zemin" (Ground) işlemidir. İki terimin etkileşime girip girmeyeceğine karar verir.

* **Kural 1 (Yapıcı Girişim / Constructive):** Eğer iki terimin durumu (Wn) aynıysa, katsayılar toplanır.
    $$A \cdot W_n \ V1 \ B \cdot W_n = (A+B) \cdot W_n$$
    
* **Kural 2 (Sönümleme / Destructive):** Eğer iki terimin durumu farklıysa, birbirlerini nötrlerler (Ortogonaldirler).
    $$A \cdot W_n \ V1 \ B \cdot W_m = 0 \quad (n \neq m)$$

* **Kural 3 (Değişme Özelliği):** Sıralama sonucu değiştirmez.
    $$A \ V1 \ B = B \ V1 \ A$$

### 2. Faz Kaydırma Operatörleri: V2 ve V3 (Phase Shifters)
V2 ve V3 operatörleri, işlem görmeden önce ikinci terimin durumunu (işaretini) değiştirir. Bu, standart matematikte bir sayının önüne eksi ($-$) koyarak işaretini ters çevirmeye benzer; ancak burada işaret "tersine" dönmez, "bir sonraki faza" kayar.

Genel işlem açılımı şöyledir:

$$\mathbf{T_1} \ \mathbf{V_y} \ \mathbf{T_2} \implies \mathbf{T_1} \ \mathbf{V1} \ (\mathbf{T_2} \times \mathbf{W_{y}})$$

Burada $V_y$ operatörü (V2 veya V3), işlem V1 tabanına indirgenirken sağdaki terimin işaretini kendi W değeriyle çarpar.

#### Operatör Dönüşüm Tablosu
| Operatör | Etkisi | Açılım Formülü |
| :---: | :--- | :--- |
| **V1** | Etkisiz (Birebir) | $aW_x \ V1 \ bW_z \rightarrow aW_x \ V1 \ b(W_z \cdot W1)$ |
| **V2** | W2 ile Çarpım | $aW_x \ V2 \ bW_z \rightarrow aW_x \ V1 \ b(W_z \cdot W2)$ |
| **V3** | W3 ile Çarpım | $aW_x \ V3 \ bW_z \rightarrow aW_x \ V1 \ b(W_z \cdot W3)$ |

### 3. İşlem Örnekleri ve Açılımlar

Sistemdeki aritmetik, **"Önce Dönüştür, Sonra Karşılaştır"** prensibiyle çalışır.

#### Örnek A: Uyumsuz Durum (Sönümleme)
Aynı düzlemde olmayan (biri W3, diğeri W2) iki sayı V1 ile işleme girerse:
$$5W3 \ V1 \ 3W2 \implies 0$$
*(Çünkü durumlar farklıdır ve V1 dönüştürme yapmaz. Kural 2 gereği sonuç sıfırdır.)*

#### Örnek B: Dönüştürerek Eşleme (Constructive Match)
Eğer operatör olarak V2 kullanılırsa, sağdaki terim dönüşür ve etkileşim mümkün olabilir.
Diyelim ki işlemimiz: $5W3 \ V2 \ 3W2$

1.  **Açılım (Expansion):** V2 operatörü, sağdaki terimi ($3W2$) $W2$ ile çarpar.
    $$5W3 \ V1 \ (3W2 \cdot W2)$$
2.  **Durum Çarpımı:** $W2 \cdot W2 = W3$ (Aksiyom gereği).
    $$5W3 \ V1 \ 3W3$$
3.  **V1 Etkileşimi:** Artık her iki taraf da $W3$ durumundadır. Kural 1 devreye girer.
    $$(5+3)W3 = 8W3$$

#### Örnek C: İkili Sistem Analojisi
Bu mantık, ikili sistemdeki çıkarma işleminin toplama işlemine indirgenmesiyle birebir aynı yapıdadır:

* **Standart (Binary):**
    $$5 - (3) \implies 5 + (3 \cdot -1)$$
    *(Eksi operatörü, sağdaki sayıyı -1 ile çarpar ve işlemi toplamaya çevirir.)*

* **TRIW (Ternary):**
    $$A \ V2 \ B \implies A \ V1 \ (B \cdot W2)$$
    *(V2 operatörü, sağdaki sayıyı W2 ile çarpar ve işlemi V1'e çevirir.)*

---
