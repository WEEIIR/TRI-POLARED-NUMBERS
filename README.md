# TRIW: 3-İşaretli 1D Aritmetik Protokolü

**TRIW**, skaler büyüklüklerin yön bilgisini geleneksel ikili ($+/-$) sistem yerine, üçlü ($W1/W2/W3$) yön mantığıyla yöneten, Öklidyen olmayan 1 Boyutlu (1D) bir aritmetik sistemdir.

Bu sistem, standart sayı doğrusunun "İleri/Geri" şeklindeki ikili yapısına alternatif olarak, aynı 1D eksen üzerinde üç farklı **geometrik yön** tanımlar.

## 📁 Sistem Özellikleri

* **Tip:** 1 Boyutlu (1D) Aritmetik
* **Geometri:** Öklidyen Olmayan (Non-Euclidean) Doğrusal
* **Yön Yapısı:** Üçlü Yön (Ternary Direction)
* **Negatiflik:** Tanımsız (Yok)
* **Grup Yapısı:** Kapalı Grup (Closed Group)

---

## ⚙️ Temel Tanımlar: Yönler (Directions)

Bu evrende sayılar, 1D eksen üzerinde tanımlı üç farklı geometrik yönden birine sahiptir. Tıpkı standart sayı doğrusunda pozitif ve negatif yönler olduğu gibi, burada da W1, W2 ve W3 yönleri vardır.

| Yön Kodu | Tanım | Rol |
| :--- | :--- | :--- |
| **W1** | **Yön 1 (Referans)** | Birim / Etkisiz Yön |
| **W2** | **Yön 2** | Aktif Yön A |
| **W3** | **Yön 3** | Aktif Yön B (Tamamlayıcı) |

---

## 🔄 Çekirdek Etkileşim (Kernel Interaction)

Bu evrende yönlerin birbiriyle çarpım (etkileşim) kuralları cebirsel olarak tanımlanmıştır. Bu kurallar döngüsel değil, işlemsel kesinliktedir.

### Çarpım Tablosu (Multiplication Truth Table)

| $\times$ | **W1** | **W2** | **W3** |
| :---: | :---: | :---: | :---: |
| **W1** | **W1** | W2 | W3 |
| **W2** | W2 | **W3** | **W1** |
| **W3** | W3 | **W1** | **W2** |

### Kritik Aksiyomlar

1.  **Birim Yön:** $X \cdot W1 = X$
2.  **Öz-Etkileşim (Self-Interaction):** Birim olmayan bir yönün kendisiyle çarpımı, sistemdeki diğer aktif yönü üretir.
    * $W2 \cdot W2 = W3$
    * $W3 \cdot W3 = W2$
3.  **Çapraz Etkileşim (Tamamlayıcılık):** Birim yöne ($W1$) ulaşmak için iki farklı aktif yönün çarpılması gerekir.
    * $W2 \cdot W3 = W1$

---

## 🧮 V-Operatör Sistemi (V-System Mechanics)

TRIW sisteminde standart toplama (+) ve çıkarma (-) operatörleri yoktur. İşlemler **V1, V2, V3** operatörleri ile yürütülür.

### 1. V1 Operatörü (Base Merge)
Temel birleştirme işlemidir. İki vektörün aynı yönde olup olmadığını kontrol eder.

* **Kural 1 (Aynı Yön):** Yönler aynıysa büyüklükler toplanır.
    $$nW_x \ V1 \ mW_x = (n+m)W_x$$
* **Kural 2 (Farklı Yön):** Yönler farklıysa birbirini sönümler (Sıfırlar).
    $$nW_x \ V1 \ mW_y = 0 \quad (x \neq y)$$
* **Kural 3 (Değişme):** $A \ V1 \ B = B \ V1 \ A$

### 2. Yön Değiştirme Operatörleri (V2 ve V3)
İşlem operatörü ($V_y$), sağdaki terimin yönünü ($W_z$) matematiksel olarak değiştirir ve işlemi V1'e indirger.

**Genel Genişletme Formülü (Expansion Formula):**
$$aW_x \ \mathbf{V_y} \ bW_z \implies aW_x \ \mathbf{V1} \ b(W_z \cdot \mathbf{W_y})$$

#### İşlem Analizi

**Örnek A: Sönümleme (V1)**
Yönler çakışmadığı için sonuç sıfırdır.
$$5W3 \ V1 \ 3W2 = 0$$

**Örnek B: Yön Değiştirerek Birleşme (V2)**
V2 operatörü sağdaki terimin yönünü W2 ile çarparak değiştirir.
1.  **İşlem:** $5W3 \ V2 \ 3W2$
2.  **Açılım:** $5W3 \ V1 \ (3W2 \cdot \mathbf{W2})$
3.  **Çarpım:** $W2 \cdot W2 = W3$ (Aksiyom gereği)
4.  **İndirgeme:** $5W3 \ V1 \ 3W3$
5.  **Sonuç:** $8W3$

**Örnek C: İkili Sistem Analojisi**
Bu yapı, ikili sistemdeki çıkarma işleminin aslında "yön değiştirme" (negatife çevirme) işlemi olmasıyla aynı mantıktadır:
* **Binary (2-Yönlü):** $5 - (3) \implies 5 + (-1 \cdot 3)$
* **Ternary (3-Yönlü):** $A \ V2 \ B \implies A \ V1 \ (W2 \cdot B)$

---

## ⚖️ Karşılaştırma: Standart vs TRIW

Her iki sistem de 1D eksen üzerinde çalışır ancak yön tanımları farklıdır.

| Özellik | Standart Sistem (Binary) | TRIW Sistemi (Ternary) |
| :--- | :--- | :--- |
| **Yön Seti** | $\{+, -\}$ (2 Yön) | $\{W1, W2, W3\}$ (3 Yön) |
| **Etkileşim Kuralı** | Aynı işaret çarpımı pozitifi verir.<br>$(-\cdot - = +)$ | Aynı yön çarpımı diğer yönü verir.<br>$(W2 \cdot W2 = W3)$ |
| **Birim Dönüşü** | Kendisiyle çarpım birimi verir.<br>$(x \cdot x = 1)$ | Tamamlayıcısı ile çarpım birimi verir.<br>$(x \cdot y = 1)$ |
| **Bölme ($1/x$)** | Ters işaret (negatif) ile çarpım. | Tamamlayıcı yön ile çarpım. |
| **İşlemciler** | $+ / -$ | $V1 / V2 / V3$ |

### 📝 Notlar
* Bu sistemde **-1 (negatif bir) yoktur.**
* Bölme işlemi ($1/W2$), sayıyı $W3$ ile çarpmak demektir.
* Vektörlerin yönleri arasındaki ilişki Öklidyen açı kurallarıyla değil, yukarıdaki etkileşim tablosuyla belirlenir.
