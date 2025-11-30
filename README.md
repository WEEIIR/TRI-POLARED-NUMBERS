# TRIW: 3-İşaretli 1D Aritmetik Protokolü

**TRIW**, skaler büyüklüklerin işaret bilgisini geleneksel ikili ($+/-$) sistem yerine, üçlü ($W1/W2/W3$) durum mantığıyla yöneten, Öklidyen olmayan deneysel bir aritmetik sistemdir.

Bu sistemde "negatiflik", "zıtlık" veya sayı doğrusunda "geri gitmek" yoktur; bunun yerine **döngüsellik** ve **tamamlayıcılık** esas alınır.

## 📁 Sistem Özellikleri

* **Tip:** 1 Boyutlu (1D) Aritmetik
* **Geometri:** Öklidyen Olmayan (Non-Euclidean)
* **Mantık:** Üçlü Durum (Ternary State)
* **Negatiflik:** Tanımsız (Yok)
* **Grup Yapısı:** Kapalı Grup (Closed Group - Abelian)

---

## ⚙️ Temel Tanımlar: Durumlar (States)

Bu evrende sayılar geometrik yönler değil, "Durumlar" (States) olarak tanımlanır. Sayı doğrusu tek bir hat (1D) olsa da, üzerindeki veriler üç farklı fazda bulunabilir.

| Durum Kodu | Tanım | Rol |
| :--- | :--- | :--- |
| **W1** | **Hareketsiz / Nötr** | Birim / Etkisiz Eleman (Referans) |
| **W2** | **Hareketli A** | Aktif Durum A |
| **W3** | **Hareketli B** | Aktif Durum B (Tamamlayıcı) |

---

## 🔄 Çekirdek Etkileşim (Kernel Interaction)

Bu evrende işaretlerin çarpım/etkileşim kuralları, standart matematikteki 2. dereceden ($-\cdot - = +$) döngü yerine, 3. dereceden bir döngüye sahiptir.

### Çarpım Tablosu (Multiplication Truth Table)

| $\times$ | **W1** | **W2** | **W3** |
| :---: | :---: | :---: | :---: |
| **W1** | **W1** | W2 | W3 |
| **W2** | W2 | **W3** | **W1** |
| **W3** | W3 | **W1** | **W2** |

### Kritik Aksiyomlar

1.  **Birim Eleman:** $X \cdot W1 = X$
2.  **Asimetrik Karesel Dönüşüm:** Birim olmayan elemanın karesi, birime değil, *diğer* elemana dönüşür.
    * $W2 \cdot W2 = W3$
    * $W3 \cdot W3 = W2$
3.  **Tamamlayıcılık (Ters Eleman):** Sistemin başa (W1) dönebilmesi için zıtlık değil, tamamlayıcılık gerekir.
    * $W2 \cdot W3 = W1$

---

## 🧮 V-Operatör Sistemi (V-System Mechanics)

TRIW sisteminde standart toplama (+) ve çıkarma (-) operatörleri yoktur. İşlemler **V1, V2, V3** operatörleri ile yürütülür. Bu operatörler, işlem öncesinde sağdaki terimin "fazını kaydırarak" taban işlemine (V1) indirger.

### 1. V1 Operatörü (Base Merge)
Temel birleştirme (zemin) işlemidir. İki terimin aynı fazda olup olmadığını kontrol eder.

* **Kural 1 (Yapıcı / Constructive):** Durumlar aynıysa toplanır.
    $$nW_x \ V1 \ mW_x = (n+m)W_x$$
* **Kural 2 (Sönümleme / Destructive):** Durumlar farklıysa birbirini yok eder (Sıfırlar).
    $$nW_x \ V1 \ mW_y = 0 \quad (x \neq y)$$
* **Kural 3 (Değişme):** $A \ V1 \ B = B \ V1 \ A$

### 2. Dönüşüm Operatörleri (V2 ve V3)
İşlem operatörü ($V_y$), sağdaki terimin durumunu ($W_z$) kendi değeriyle çarparak değiştirir ve işlemi V1'e indirger.

**Genel Genişletme Formülü (Expansion Formula):**
$$aW_x \ \mathbf{V_y} \ bW_z \implies aW_x \ \mathbf{V1} \ b(W_z \cdot \mathbf{W_y})$$

#### İşlem Analizi ve Örnekler

**Örnek A: Sönümleme (V1)**
Fazlar farklı olduğu için etkileşim olmaz.
$$5W3 \ V1 \ 3W2 = 0$$

**Örnek B: Dönüşümlü Birleşme (V2)**
V2 operatörü sağdaki terimi W2 ile çarparak fazını kaydırır.
1.  **İşlem:** $5W3 \ V2 \ 3W2$
2.  **Açılım:** $5W3 \ V1 \ (3W2 \cdot \mathbf{W2})$
3.  **Çarpım:** $W2 \cdot W2 = W3$ (Aksiyom gereği)
4.  **İndirgeme:** $5W3 \ V1 \ 3W3$
5.  **Sonuç:** $8W3$

**Örnek C: İkili Sistem Analojisi**
Bu yapı, ikili sistemdeki çıkarma işleminin aslında "negatif ile toplama" olmasıyla aynı mantıktadır:
* **Binary:** $5 - (3) \implies 5 + (-1 \cdot 3)$
* **Ternary:** $A \ V2 \ B \implies A \ V1 \ (W2 \cdot B)$

---

## ⚖️ Karşılaştırma: Standart vs TRIW

| Özellik | Standart Sistem (Binary) | TRIW Sistemi (Ternary) |
| :--- | :--- | :--- |
| **İşaret Seti** | $\{+, -\}$ | $\{W1, W2, W3\}$ |
| **Döngü** | 2. Dereceden ($-\cdot - = +$) | 3. Dereceden ($W2 \cdot W2 = W3$) |
| **Tersinirlik** | Kendisiyle çarpım birimi verir. ($x^2=1$) | Tamamlayıcısı ile çarpım birimi verir. ($xy=1$) |
| **Bölme ($1/x$)** | Ters işaret ile çarpım. | Tamamlayıcı işaret ile çarpım. |
| **Toplama/Çıkarma** | $+ / -$ Operatörleri | $V1 / V2 / V3$ Operatörleri |

### 📝 Notlar
* Bu sistemde **-1 (negatif bir) yoktur.**
* Bölme işlemi ($1/W2$), sayıyı $W3$ ile çarpmak demektir.
* Sistem, elektronik 3 fazlı sistemlerin veya kuantum renk yüklerinin 1D aritmetik simülasyonu olarak düşünülebilir.
