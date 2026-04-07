# 🎵 C Music Player (Linked List Implementation)

Bu proje, **C dili** kullanılarak geliştirilmiş, veri yapıları dersi kapsamında "Bağlı Liste" (Linked List) mantığını gerçek bir senaryoda uygulayan bir müzik çalar yönetim simülasyonudur. 


## 🚀 Öne Çıkan Özellikler

Uygulama, temel bağlı liste operasyonlarının yanı sıra şu ileri seviye fonksiyonları içerir:

* **Dinamik Sıralı Ekleme:** Şarkılar, alfabetik olarak (isime göre) otomatik sıralanarak listeye eklenir.
* **Node Swap (Düğüm Takası):** Veri kopyalamak yerine, düğümlerin bellek adresleri (pointer manipülasyonu) üzerinden yer değiştirme işlemi yapılır.
* **Shuffle (Karıştırma):** Rastgelelik algoritması kullanılarak listenin sırası tamamen karıştırılır.
* **İstatistik Paneli:** Listenin toplam süresini ve en uzun şarkı gibi verileri hesaplayan analiz aracı.
* **Simüle Edilmiş Çalma:** `sleep()` fonksiyonu ve terminal çıktıları ile gerçekçi bir müzik dinleme deneyimi.



## 🛠 Kullanılan Veri Yapıları ve Mantık

- **Singly Linked List:** Şarkıların hafızada dinamik olarak tutulması için kullanıldı.
- **Pointer Aritmetiği:** Düğüm takasları ve liste gezintileri için yoğun pointer kullanımı yapıldı.
- **Memory Management:** `malloc` ile ayrılan her alanın, program çıkışında `free` edilmesi sağlanarak bellek sızıntıları (memory leaks) önlendi.
