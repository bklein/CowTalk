#ifdef __cplusplus
extern "C" {
#endif

struct CowTalkHandle;
typedef struct CowTalkHandle CowTalkHandle;

CowTalkHandle* CowTalk_Create();

const char* CowTalk_Talk(const CowTalkHandle* const handle);
const char* CowTalk_Touch(CowTalkHandle* handle);
int CowTalk_TimesTouched(const CowTalkHandle* const handle);

void CowTalk_Destroy(void* p);

#ifdef __cplusplus
}  // extern "C"
#endif
