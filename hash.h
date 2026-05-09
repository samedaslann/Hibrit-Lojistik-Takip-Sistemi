#ifndef HASH_H
#define HASH_H

#define TABLE_SIZE 10

typedef struct {
    int packet_id;
    char content[50];
    int current_city_id;
    int is_empty; // 1: boş, 0: dolu
} Packet;

void initHashTable(Packet table[]);
int hashFunction(int key);
void insertPacket(Packet table[], int id, const char* content, int city_id);
void searchPacket(Packet table[], int id);

#endif
