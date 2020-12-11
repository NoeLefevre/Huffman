#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Decompress/Decompress.h"
#include "Conversion/Conversion.h"
#include "Decompression.h"
#include "Libération/Liberation.h"
void Decompression()
{
    FILE* dictio = NULL;
    FILE* Encodage = NULL;
    Node* huff_2 = NULL;
    clock_t t1;
    clock_t t2;
    long clk_tck = CLOCKS_PER_SEC;
    fopen_s(&Encodage, "Encodeur.txt", "r+");
    if (fgetc(Encodage) == EOF)
        printf("Il n'y a pas de fichier a decompresser");
    else
    {
        fseek(Encodage, 0, SEEK_SET);
        fopen_s(&dictio, "dictionnaire.txt", "r+");
        FILE* trad = NULL;
        fseek(dictio, 0, SEEK_SET);
        huff_2 = create_huff(dictio);
        fclose(dictio);
        t1 = clock();
        trad = decompress(Encodage, huff_2);
        t2 = clock();
        printf("Temps de decompression = %lf s\n", (t2 - t1) / (double)clk_tck);
        fclose(Encodage);
        free_node(huff_2);
        fclose(trad);
        printf("Veuilez recuperer votre fichier dans <trad>");
    }
    
}
