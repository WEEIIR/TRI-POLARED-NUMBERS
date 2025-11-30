# TRI-POLARED-NUMBERS

Bu belge, standart ikili (pozitif/negatif) sayı sistemi yerine, **tek boyut (1D) üzerinde üç farklı yönün** tanımlandığı, Öklid dışı (Non-Euclidean) bir aritmetik sistem olan TRIW'in mantığını, aksiyomlarını ve çalışma prensiplerini açıklar.

## 1. Sistemin Amacı ve Felsefesi

Geleneksel matematikte sayılar bir doğru üzerinde $0$ noktasına göre simetrik iki yöne (Sağ/Sol veya +/-) sahiptir. Bu sistemde "tersin tersi kendisidir" ($- \times - = +$) kuralı geçerlidir. Bu, **antagonistik (karşıtlık temelli)** bir evren modelidir.

**TRIW Sistemi** ise 1 Boyutlu uzayda **tek karşıtlığı reddeder**. Bunun yerine **çok yönlü karşıtlar** esas alır. Bir yöne gitmekte olan bir varlık, tersine dönmek için durup geri gitmez; döngüyü tamamlayarak başa döner.

### Temel Tanım
Sistem hala **1 Boyutludur (1D)**. Ancak bu boyut üzerindeki hareket, skaler bir büyüklüğün yanında, W1, W2 ve W3 olarak adlandırılan üç farklı "faz" veya "yönelim" ile ifade edilir.

## 2. Standart "Eksi" Sisteminden Farkları

| Özellik | Standart Sistem (+/-) | TRIW Sistemi (W1/W2/W3) |
| :--- | :--- | :--- |
| **Boyut Yapısı** | 1D (Doğrusal / Zıt) | 1D (Döngüsel / Fazlı) |
| **Yön Sayısı** | 2 (Pozitif, Negatif) | 3 (W1, W2, W3) |
| **Tersin Tersi** | Kendisidir ($-- \to +$) | Başka bir yöndür ($W2 \cdot W2 \to W3$) |
| **Birim Eleman** | +1 | W1 |
| **Denge Noktası** | 0 (Toplamsal Yutan) | W1 (Çarpımsal Birim / Referans) |
| **Geometri** | Vektörel (180° zıtlık) | Öklid Dışı (Açısal olmayan yönelim) |

## 3. Aksiyomlar ve Kurallar

Bu sistemin kuralları, "hiçbir yönün diğerinin tam zıttı olmadığı, sadece bir sonraki aşaması olduğu" prensibine göre türetilmiştir.

### Aksiyom 1: Referans Yönü (W1)
W1, sistemin "doğal" halidir. Standart matematikteki Pozitif (+) yüke veya Birim (Identity) elemana karşılık gelir.
* `Herhangi bir yön` * `W1` = `Kendisi`

### Aksiyom 2: İlerleme İlkesi (Self-Interaction)
Standart matematikte bir eksiyi kendisiyle çarparsanız artıya (başa) dönersiniz. TRIW evreninde ise bir yön (W2) kendisiyle etkileşime girdiğinde başa dönmez, bir sonraki faza (W3) geçer.
* **W2 * W2 = W3** (Kendisiyle çarpım, sistemi ileriye taşır.)
* **W3 * W3 = W2** (W3'ün karesi, döngüsel olarak W2'ye düşer.)

### Aksiyom 3: Tamamlama İlkesi (Mutual-Interaction)
Sistemin başa (W1 - Referans haline) dönebilmesi için, iki farklı sapma yönünün (W2 ve W3) birleşmesi gerekir.
* **W2 * W3 = W1** (İki farklı yön birleştiğinde denge sağlanır.)

## 4. Bu Evrenin Geometrisi (Öklid Dışı 1D)

Bu sistemde "açı" kavramı, bildiğimiz 2D düzlemdeki iletki açısı değildir. Buradaki açılar, sayı doğrusunun kendi içindeki bükülmeleridir.

* **Neden 1D?** Veri tek bir hatta akar (bir kablo, bir zaman serisi). Ancak verinin "rengi" veya "tadı" değişir.
* **Görselleştirme:** Bunu düz bir çizgi yerine, ucundan bakıldığında üç yapraklı bir yonca gibi görünen, ancak yan taraftan bakıldığında tek bir çizgi gibi duran bir yapı olarak düşünebilirsiniz.
    * W1 hattı
    * W2 hattı
    * W3 hattı

Bu hatlar birbirine paralel değildir, birbirinin içindedir. Sayı doğrusu üzerinde "geri gitmek" yoktur, sadece yön değiştirmek (W1->W2->W3->W1) vardır.

## 5. Hesaplama Mantığı (Çarpım Tablosu)

Sistemin "Truth Table" (Doğruluk Tablosu) şöyledir:

| * | **W1** | **W2** | **W3** |
| :---: | :---: | :---: | :---: |
| **W1** | W1 | W2 | W3 |
| **W2** | W2 | **W3** | **W1** |
| **W3** | W3 | **W1** | **W2** |

> **Not:** Bu tablo, Abelyen (değişmeli) bir gruptur. Sıralama sonucu değiştirmez (W2 * W3 = W3 * W2).

---
*Bu sistem, `TRIFLOAT32` veri yapısı altında C++ ile simüle edilmiştir.*
