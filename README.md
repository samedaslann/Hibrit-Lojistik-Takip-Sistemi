# 🚚 Hibrit Lojistik Yönetim Sistemi

Bu proje, Kırklareli Üniversitesi Veri Yapıları dersi kapsamında geliştirilmiş; paket sorgulama ve şehirler arası rota yönetimini hibrit veri yapıları (Hash Tablosu ve Graf) kullanarak çözen bir C konsol uygulamasıdır.

## 🎯 Proje Amacı
Lojistik ağındaki şehirler arası bağlantıların dinamik bellek tahsisiyle (Adjacency List) yönetildiği bir **Graf** yapısı ile, sisteme giren kargoların $O(1)$ karmaşıklığına en yakın sürede bulunabilmesi için indekslendiği bir **Hash Tablosu** yapısının entegre çalışmasını sağlamaktır.

## ⚙️ Kullanılan Teknikler ve Algoritmalar

Öğrenci numarasına (1250505003) bağlı olarak projede spesifik algoritmalar kullanılmıştır:

*   **Hash Fonksiyonu (Tip B):** Altın Oran ($A \approx 0.618$) kullanılarak "Çarpma Yöntemi" ile indeksleme yapılmıştır.
*   **Çakışma Çözümü (Collision):** Açık Adresleme (Linear Probing) kullanılmıştır. İndeks doluysa, modüler aritmetik ile bir sonraki boş hücreye geçilir.
*   **Graf Gezinme (BFS):** Şehirler arası rotasyon hesaplaması için kuyruk (Queue) yapısına dayalı Genişlik Öncelikli Arama (Breadth-First Search) algoritması kullanılmıştır.

## 📂 Proje Mimarisi

Spagetti koddan kaçınılarak, sistem mantıksal katmanlarına göre çoklu dosya mimarisinde tasarlanmıştır:

```text
├── src/
│   ├── main.c       # Ana program döngüsü ve test senaryoları
│   ├── hash.c       # Hash Tablosu metodları (insert, search, hashFunction)
│   ├── hash.h       # Hash Tablosu veri yapıları (struct Packet)
│   ├── graph.c      # Graf metodları (addEdge, BFS)
│   └── graph.h      # Graf veri yapıları (struct Graph, struct EdgeNode)
├── docs/
│   └── Bellek_Izleme_Raporu.pdf  # Dinamik bellek adreslerinin şematik analizi
└── README.md# Hibrit-Lojistik-Takip-Sistemi
