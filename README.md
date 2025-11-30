TRIW: 3-İşaretli 1D Aritmetik Protokolü

TRIW, skaler büyüklüklerin işaret bilgisini geleneksel ikili ($+/-$) sistem yerine, üçlü ($W1/W2/W3$) durum mantığıyla yöneten deneysel bir aritmetik sistemdir.

📁 Sistem Özellikleri

Tip: 1 Boyutlu (1D) Aritmetik

Geometri: Öklidyen Olmayan (Non-Euclidean)

Mantık: Üçlü Durum (Ternary State)

Negatiflik: Tanımsız (Yok)

⚙️ Temel Tanımlar

Sayılar geometrik yönler değil, "Durumlar" (States) olarak tanımlanır.

Durum Kodu

Tanım

Rol

W1

Hareketsiz

Birim / Etkisiz Eleman

W2

Hareketli

Aktif Durum A

W3

Hareketli

Aktif Durum B (Tamamlayıcı)

🧮 Operatör Mantığı (V-Sistemi)

Sistemde standart + ve - yoktur. İşlemler V1, V2, V3 operatörleri ile yürütülür.

1. V1 Operatörü (Base Merge)

Temel birleştirme işlemidir.

Kural 1 (Aynı): $Wn \ V1 \ Wn = 2Wn$

Kural 2 (Farklı): $Wn \ V1 \ Wm = 0$ (Sönümleme)

Kural 3 (Değişme): $A \ V1 \ B = B \ V1 \ A$

2. Dönüşüm Operatörleri (V2, V3)

İşlem operatörü ($Vy$), ikinci terimin durumunu ($Wz$) çarpanlarına ayırarak değiştirir. İşlem V1 tabanına indirgenir.

Genel Formül:

aWx \ Vy \ bWz \implies aWx \ V1 \ b(Wz \cdot Wy)


🔄 Çekirdek Etkileşim (Kernel Interaction)

Bu evrende işaretlerin çarpım/etkileşim kuralları 3. dereceden bir döngüye sahiptir.

Çarpım Tablosu

x

W1

W2

W3

W1

W1

W2

W3

W2

W2

W3

W1

W3

W3

W1

W2

Kritik Aksiyomlar

Birim: $X \cdot W1 = X$

Karesel Dönüşüm: Birim olmayan elemanın karesi, diğer elemanı verir.

$W2 \cdot W2 = W3$

$W3 \cdot W3 = W2$

Tamamlayıcılık: Birim elemana ($W1$) dönmek için zıtlık değil, tamamlayıcılık gerekir.

$W2 \cdot W3 = W1$

⚖️ Standart Sistem (Binary) vs TRIW

Özellik

Standart (Binary)

TRIW (Ternary)

Set

$\{+, -\}$

$\{W1, W2, W3\}$

Döngü

2. Dereceden ($-\cdot - = +$)

3. Dereceden ($W2 \cdot W2 = W3$)

Tersinirlik

Kendisiyle çarpım birimi verir.

Tamamlayıcısı ile çarpım birimi verir.

Bölme

Ters işaret ile çarpım.

Tamamlayıcı işaret ile çarpım.

📝 Kullanım Notları

Bu sistemde $-1$ (negatif bir) yoktur.

Bölme işlemi ($1/x$), sayıyı sistemdeki "tamamlayıcı" işaretiyle çarpmak demektir.

Örnek: $W2$'ye bölmek $\equiv W3$ ile çarpmaktır.

Sistem kapalı bir gruptur (Closed Group).
