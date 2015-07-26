#ifdef __cplusplus
extern "C" {
#endif

struct CowTalkHandle;
typedef struct CowTalkHandle* CowTalkHandlePtr;

CowTalkHandlePtr CowTalk_Create();

char* CowTalk_Talk(CowTalkHandlePtr p);

void CowTalk_Destroy(void* p);

#ifdef __cplusplus
}  // extern "C"
#endif
