#ifndef __message_h__
#define __message_h__

#define M_INIT (1)
#define M_LOOKUP (2)
#define M_STAT (3)
#define M_WRITE (4)
#define M_READ (5)
#define M_CREAT (6)
#define M_UNLINK (7)
#define M_SHUTDOWN (8)

typedef struct {
    int mtype;  // message type
    int rc;     // return code
    int inum;
    int offset;
    int nbytes;
    int size;
    int type;
    char name[28];
    char buffer[4096];
} message_t;

#endif // __message_h__