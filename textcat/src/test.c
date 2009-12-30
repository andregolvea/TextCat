#include "textcat.h"

int main()
{
    char  * text[] = {"Have you tried turn it off and on again", "another foobar testing"};
    TextCat * tc;
    NGrams * t1, * t2;
    int i;
    TextCat_Init(&tc);
        TextCat_parse(tc, text[0], strlen(text[0]),&t2);
        if (TextCat_parse_file(tc, "./test.txt", &t1) == TC_TRUE) {
            /*for (i=0; i < t1->size; i++) {
                printf("Token=(%s), Freq=%d, Post=%d\n", t1->ngram[i].str, t1->ngram[i].freq, t1->ngram[i].position+1);
            }*/
        }
        TextCat_save(tc, "english.txt");
        TextCat_reset(tc);
        TextCat_parse(tc, text[1], strlen(text[1]), &t2);


        /* list files */
        uchar ** files;
        int len;
        tc->list(tc, &files, &len);
        for (i=0; i < len; i++) {
            printf("lanaguage: %s\n", files[i]);
        }

    TextCat_Destroy(tc);
}
