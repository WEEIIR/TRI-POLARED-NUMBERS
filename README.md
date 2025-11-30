# TRIW: 3-İşaretli 1D Aritmetik Sistemi

Bu belge, standart aritmetikteki 2 durumlu işaret kavramını ($+/-$), 1 Boyutlu uzayda 3 durumlu bir yapıya ($W1/W2/W3$) dönüştüren TRIW sisteminin teknik tanımını ve aksiyomlarını içerir.

## 1. Sistemin Tanımı

TRIW, skaler bir büyüklüğün önündeki nitelik (işaret) bilgisinin, geleneksel ikili mantık yerine üçlü bir mantık kümesiyle yönetildiği bir aritmetik sistemdir.

Sistem 1 Boyutludur (1D). Sayılar tek bir eksen üzerinde tanımlıdır ancak bu eksen üzerindeki değerler üç farklı "durum"dan (State) birine sahip olabilir.
Hayal etmeye çalışmayın çünkü bizim evrernimizde doğrular 2 yönlü, 3 değil. bu sistem Öklidyen geometrden çok farklı ve bir o kadar benzer ilginç bir yapıya sahiptir.
## 2. Standart Sistem ile Yapısal Farklar

Her iki sistem de cebirsel olarak kapalı (closed) birer gruptur. Fark, grubun eleman sayısı ve etkileşim kurallarıdır.

| Özellik | Standart İkili Sistem | TRIW Üçlü Sistemi |
| :--- | :--- | :--- |
| **İşaret Kümesi** | $\{+, -\}$ (2 Eleman) | $\{W1, W2, W3\}$ (3 Eleman) |
| **Birim Eleman** | $+$ (Pozitif) | $W1$ |
| **Operatör Periyodu** | 2. Dereceden (Order 2)<br>$(-) \times (-) = (+)$ | 3. Dereceden (Order 3)<br>$W2 \times W2 = W3$ |
| **Ters İşlem** | Kendisiyle çarpım birim elemanı verir.<br>$x = x^{-1}$ ($-1$ için) | Kendisiyle çarpım *diğer* elemanı verir.<br>$x \neq x^{-1}$ (W2 ve W3 için) |

## 3. Aksiyomlar

ikili sistemde +(hareketsiz) ve -(hareketli) iki yön vardır bizde W2,W3 (hareketli) ve W1 (hareketsiz) üç yön vardır
ikili sistemde - nin sönümleyicisi - dir ($(-) \times (-) = (+)$)

üçlü sistemde ise W2 nin sönümleyicisi W3 ve tam tersi W2*W3 = W1

ve burda da $A \times B = B \times A$ dır

### Aksiyom 1: Birim Eleman (W1)
W1, sistemin etkisiz elemanıdır. Sayısal değeri veya işareti değiştirmez.
* $X \cdot W1 = X$

### Aksiyom 2: Asimetrik Karesel Dönüşüm
Standart sistemde birim olmayan elemanın karesi birim elemanı verir ($-\cdot - = +$).
TRIW sisteminde, birim olmayan bir elemanın karesi, birim elemanı **vermez**; üçüncü durumu (tamamlayıcıyı) oluşturur.

* $W2 \cdot W2 = W3$
* $W3 \cdot W3 = W2$ *(Matematiksel not: $W3$, $W2$'nin karesi gibi davranırsa, $W3$'ün karesi $W2^4$ olur, bu da $W2$'ye denktir)*

### Aksiyom 3: Tamamlayıcılık (Ters Eleman)
Sistemin birim elemana (W1) dönebilmesi için iki "aynı" işaretin değil, iki "tamamlayıcı" işaretin çarpılması gerekir.

* $W2 \cdot W3 = W1$

## 4. Etkileşim Tablosu (Interaction Table)

Bu evrendeki işaretlerin çarpım kuralı aşağıdaki gibidir:

| $\times$ | **W1** | **W2** | **W3** |
| :---: | :---: | :---: | :---: |
| **W1** | W1 | W2 | W3 |
| **W2** | W2 | **W3** | **W1** |
| **W3** | W3 | **W1** | **W2** |

## 5. Neden Öklüdyen Değil?

Öklid geometrisi ve standart reel sayılar ekseni, büyüklüklerin yönelimini 180 derecelik zıtlıklar (tersinirlik) üzerine kurar. TRIW sisteminde ise "zıtlık" (negation) kavramı yoktur. Bunun yerine 3 parçalı bir durum uzayı vardır.

Bu sistemde:
* **$-1$ yoktur.** (Bir sayıyı negatifiyle çarparak pozitif yapamazsınız).
* **Bölme işlemi ($1/x$):** Bir sayıyı bölmek, onu sistemdeki "tamamlayıcı" işaretiyle çarpmak demektir. ($W2$'ye bölmek, $W3$ ile çarpmaktır).

Bu yapı, sayı doğrusunun kurallarını değiştiren, kendi içinde tutarlı, alternatif bir 1D aritmetiktir.
