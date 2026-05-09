#include <stdio.h>
#include <string.h>
#include "hash.h"

void initHashTable(Packet table[]) {
	int i ;
    for ( i = 0; i < TABLE_SIZE; i++) {
        table[i].is_empty = 1;
    }
}

// Tip B Hash Fonksiyonu
int hashFunction(int key) {
    double A = 0.6180339887;
    double val = key * A;
    val = val - (long)val; // Sadece kesirli kısmı al
    return (int)(TABLE_SIZE * val);
}

// Açık Adresleme (Linear Probing) ile Ekleme
void insertPacket(Packet table[], int id, const char* content, int city_id) {
    int index = hashFunction(id);
    int original_index = index;

    while (table[index].is_empty == 0) {
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) {
            printf("Hash tablosu dolu!\n");
            return;
        }
    }

    table[index].packet_id = id;
    strcpy(table[index].content, content);
    table[index].current_city_id = city_id;
    table[index].is_empty = 0;

    printf("Paket %d eklendi. Index: %d, Bellek Adresi: %p\n", id, index, (void*)&table[index]);
}

void searchPacket(Packet table[], int id) {
    int index = hashFunction(id);
    int original_index = index;

    while (table[index].is_empty == 0) {
        if (table[index].packet_id == id) {
            printf("Paket Bulundu! ID: %d, Icerik: %s, Sehir ID: %d\n", 
                   table[index].packet_id, table[index].content, table[index].current_city_id);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) break;
    }
    printf("Paket %d bulunamadi.\n", id);
}
