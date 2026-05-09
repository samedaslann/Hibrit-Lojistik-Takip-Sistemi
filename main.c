#include <stdio.h>
#include "hash.h"
#include "graph.h"

int main() {
    Packet hashTable[TABLE_SIZE];
    Graph cityGraph;

    printf("--- LOJISTIK SISTEMI BASLATILIYOR ---\n\n");

    // Sistem başlatma
    initHashTable(hashTable);
    initGraph(&cityGraph);

    // 1. Graf Bağlantıları (Şehirler: 0=Antalya, 1=Kırklareli, 2=İstanbul, 3=Ankara, 4=İzmir)
    printf("[ SISTEM ] Sehir Baglantilari Olusturuluyor (Dinamik Bellek)...\n");
    addEdge(&cityGraph, 0, 1);
    addEdge(&cityGraph, 0, 2);
    addEdge(&cityGraph, 1, 3);
    addEdge(&cityGraph, 2, 4);

    // 2. BFS Testi
    BFS(&cityGraph, 0);

    // 3. Hash Tablosuna Paket Ekleme
    printf("\n[ SISTEM ] Paketler Sisteme Giriliyor...\n");
    insertPacket(hashTable, 1001, "Elektronik Esya", 0);
    insertPacket(hashTable, 2045, "Mobilya", 1);
    insertPacket(hashTable, 3056, "Kitap", 2);
    insertPacket(hashTable, 4099, "Gida", 3);
    insertPacket(hashTable, 5012, "Tekstil", 4);

    // 4. Hash Tablosunda Arama
    printf("\n[ SISTEM ] Paket Sorgulama...\n");
    searchPacket(hashTable, 3056);
    searchPacket(hashTable, 9999);

    return 0;
}
