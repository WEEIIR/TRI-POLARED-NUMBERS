# TRIW: Üç Yönlü Tek Boyutlu (1D) Matematik Modeli

**TRIW**, geleneksel ikili (Binary) aritmetiğin "+/-" kutupsallığını reddeden, bunun yerine tek boyutlu bir eksen üzerinde üç farklı asal yönün ($W1, W2, W3$) varlığını kabul eden aksiyomatik bir matematik sistemidir.

Bu model, mevcut veri setlerine veya standart aritmetik kabullerine uymak zorunda değildir; kendi tanımlı aksiyomları üzerinde çalışan kapalı bir sistemdir.

## 1. Sistemin Doğası ve Varlık Tanımı

Bu evrende sayılar sadece büyüklük (skaler) değil, ayrılmaz bir **Yön (Direction)** bilgisi taşır. Bu yönler geometrik birer vektördür ancak Öklid uzayındaki açılarla değil, **Etkileşim Kuralları** ile tanımlanır.

### Varlık Kümesi
Sistem, $\mathbb{T}$ kümesi üzerinde tanımlıdır:
$$\mathbb{T} = \{ n \cdot W_x \mid n \in \mathbb{R}, \ W_x \in \{W1, W2, W3\} \}$$

* **Boyut:** 1D (Tek Eksen)
* **Yön Sayısı:** 3 (Ternary)
* **Negatiflik:** Yoktur. (Yönler birbirinin zıttı değil, bağımsız varyasyonlarıdır.)

## 2. Temel Aksiyomlar

Sistemin işleyişi aşağıdaki değişmez kurallara (Postulates) dayanır:

### Aksiyom I: Referans ve Korunum
**W1**, sistemin referans yönüdür (Birim Eleman).
* Herhangi bir yönün W1 ile etkileşimi, yönün kendisini korur.
    $$W_n \times W1 = W_n$$

### Aksiyom II: Öz-Etkileşim (Self-Interaction)
Birim olmayan bir yön, kendisiyle etkileşime girdiğinde (karesi alındığında) sistemdeki **diğer** aktif yöne dönüşür.
* $W2 \times W2 = W3$
* $W3 \times W3 = W2$

### Aksiyom III: Çapraz Tamamlama (Cross-Completion)
Sistemin referans haline ($W1$) dönebilmesi için iki farklı aktif yönün çarpılması gerekir.
* $W2 \times W3 = W1$

## 3. Cebirsel Yapı: Çarpım Tablosu

Yönlerin birbiriyle olan ilişkisi aşağıdaki "Etkileşim Matrisi" ile belirlenir:

| $\times$ | **W1** | **W2** | **W3** |
| :---: | :---: | :---: | :---: |
| **W1** | **W1** | W2 | W3 |
| **W2** | W2 | **W3** | **W1** |
| **W3** | W3 | **W1** | **W2** |

> **Not:** Bu tablo, sistemin değişmeli (Abelian) bir grup olduğunu gösterir. Sıralama sonucu değiştirmez.

## 4. Aritmetik Operatörler: V-Sistemi

Bu matematik modelinde Standart Toplama (+) ve Çıkarma (-) işlemleri **tanımsızdır**. Yerine, yönlerin durumuna göre işlem yapan **V Operatörleri** ($V1, V2, V3$) kullanılır.

Tüm işlemler nihayetinde $V1$ tabanına indirgenir.

### 4.1. V1 Operatörü (Base Merge / Zemin İşlemi)
V1, iki varlığın aynı yönde olup olmadığını denetler.

* **Kural A (Aynı Yön):** Yönler aynı ise büyüklükler toplanır.
    $$A \cdot W_x \ \mathbf{V1} \ B \cdot W_x = (A + B)W_x$$
* **Kural B (Ortogonalite / Sönümleme):** Yönler farklı ise sonuç yoktur (Sıfırdır).
    $$A \cdot W_x \ \mathbf{V1} \ B \cdot W_y = 0 \quad (Eğer \ x \neq y)$$

### 4.2. Dönüşüm Operatörleri (V2 ve V3)
$V2$ ve $V3$, işleme giren ikinci terimin yönünü manipüle ederek V1 zeminine hazırlar.

**Genel Teorem (Operatör Genişletmesi):**
Bir $V_y$ işlemi, sağdaki terimin ($W_z$) yönünü, operatörün kendi karakteristiği ($W_y$) ile çarparak değiştirir.

$$\mathbf{Sol} \ \mathbf{V_y} \ \mathbf{Sağ} \implies \mathbf{Sol} \ \mathbf{V1} \ (\mathbf{Sağ} \times \mathbf{W_y})$$

#### İspat ve Uygulama:

**Durum 1: $5W3 \ V2 \ 3W2$ İşlemi**
1.  Operatör $V2$'dir. Sağdaki terim ($3W2$), $W2$ ile çarpılır.
    $$\rightarrow 5W3 \ V1 \ (3W2 \times W2)$$
2.  Aksiyom II gereği ($W2 \times W2 = W3$):
    $$\rightarrow 5W3 \ V1 \ 3W3$$
3.  Yönler eşitlendi ($W3$). V1 Kural A devreye girer:
    $$\rightarrow 8W3$$

**Durum 2: $5W3 \ V1 \ 3W2$ İşlemi**
1.  Operatör $V1$'dir. (Etkisiz çarpım: $W2 \times W1 = W2$)
2.  Yönler farklı ($W3$ ve $W2$).
3.  V1 Kural B gereği:
    $$\rightarrow 0$$

## 5. İkili (Binary) Sistem ile Model Karşılaştırması

Bu model, ikili sistemin bir varyasyonu değil, tamamen farklı bir topolojiye sahip alternatifidir.

| Konsept | Standart Model (Binary) | TRIW Modeli (Ternary) |
| :--- | :--- | :--- |
| **Uzay** | 1D (2 Yönlü: $+,-$) | 1D (3 Yönlü: $W1, W2, W3$) |
| **Birim (Identity)** | $+1$ | $W1$ |
| **Tersinirlik** | Kendisiyle çarpım birimi verir ($x^2=1$) | Tamamlayıcısıyla çarpım birimi verir ($xy=1$) |
| **İşlem Yöntemi** | İşaret değişimi ($-$) ile toplama | Yön çarpımı ($V_n$) ile birleştirme |
| **Sıfırlama** | Zıtların toplamı ($1 + (-1) = 0$) | Farklıların etkileşimi ($W1 \ V1 \ W2 = 0$) |

### Sonuç
TRIW, tek boyutlu uzayda yön kavramını ikili (binary) kısıtlamadan kurtarıp, üçlü bir etkileşim ağına oturtan özgün bir matematiksel yapıdır.
