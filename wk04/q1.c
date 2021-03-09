#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int zid;
    char name[15];
};

typedef struct record *Record;

void RecordShow(Record r) {
    printf("%d|%s\n", r->zid, r->name);
}

/**
 *  Pre: size > 0
 */
Record func(Record students, int size,
            int (*cmp)(Record, Record))
{
    Record rec = &students[0];

    if (size == 1) return rec;

    for (int i = 1; i < size; i++) {
        if (cmp(&students[i], rec) < 0) {
            rec =  &students[i];
        }
    }

    return rec; 
}

int cmpId(Record r1, Record r2) {
    // (a)
    return (r1->zid - r2->zid); 
}

int myCmpId(Record r1, Record r2) {
    // TODO: (b)
    return (r2->zid - r1->zid);
}

int myCmpName(Record r1, Record r2) {
    // TODO: (c)
    return strcmp(r2->name, r1->name);
}

int main(void) {
    struct record students[] = {
        { 2134567, "John" },
        { 3312902, "Mary" },
        { 1249805, "Rita" },
        { 2209067, "Dawn" },
        { 1239876, "Jack" },
    }; 

    Record myRec1 = func(students, 5, cmpId);
    RecordShow(myRec1);

    Record myRec2 = func(students, 5, myCmpId);
    RecordShow(myRec2);

    Record myRec3 = func(students, 5, myCmpName);
    RecordShow(myRec3);
}