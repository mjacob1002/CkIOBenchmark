#ifndef _DECL_iotest_H_
#define _DECL_iotest_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
#include "ckio.h"

/* DECLS: readonly CProxy_Main mainProxy;
 */

/* DECLS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void ready(Ck::IO::FileReadyMsg* impl_msg);
void startRead(Ck::IO::SessionReadyMsg* impl_msg);
void doneReading(CkReductionMsg* impl_msg);
void logging(CkReductionMsg* impl_msg);
void postClose(CkReductionMsg* impl_msg);
void decrementCount();
void startReading();
};
 */
 class Main;
 class CkIndex_Main;
 class CProxy_Main;
/* --------------- index object ------------------ */
class CkIndex_Main:public CkIndex_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Main(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Main_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Main_CkArgMsg() {
      static int epidx = reg_Main_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Main_CkArgMsg(); }
    
    static void _call_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void ready(Ck::IO::FileReadyMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_ready_FileReadyMsg();
    // Entry point index lookup
    
    inline static int idx_ready_FileReadyMsg() {
      static int epidx = reg_ready_FileReadyMsg();
      return epidx;
    }

    
    inline static int idx_ready(void (Main::*)(Ck::IO::FileReadyMsg* impl_msg) ) {
      return idx_ready_FileReadyMsg();
    }


    
    static int ready(Ck::IO::FileReadyMsg* impl_msg) { return idx_ready_FileReadyMsg(); }
    
    static void _call_ready_FileReadyMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_ready_FileReadyMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void startRead(Ck::IO::SessionReadyMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_startRead_SessionReadyMsg();
    // Entry point index lookup
    
    inline static int idx_startRead_SessionReadyMsg() {
      static int epidx = reg_startRead_SessionReadyMsg();
      return epidx;
    }

    
    inline static int idx_startRead(void (Main::*)(Ck::IO::SessionReadyMsg* impl_msg) ) {
      return idx_startRead_SessionReadyMsg();
    }


    
    static int startRead(Ck::IO::SessionReadyMsg* impl_msg) { return idx_startRead_SessionReadyMsg(); }
    
    static void _call_startRead_SessionReadyMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_startRead_SessionReadyMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void doneReading(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_doneReading_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_doneReading_CkReductionMsg() {
      static int epidx = reg_doneReading_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_doneReading(void (Main::*)(CkReductionMsg* impl_msg) ) {
      return idx_doneReading_CkReductionMsg();
    }


    
    static int doneReading(CkReductionMsg* impl_msg) { return idx_doneReading_CkReductionMsg(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_doneReading_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_doneReading_CkReductionMsg() {
      static int epidx = reg_redn_wrapper_doneReading_CkReductionMsg();
      return epidx;
    }
    
    static int redn_wrapper_doneReading(CkReductionMsg* impl_msg) { return idx_redn_wrapper_doneReading_CkReductionMsg(); }
    
    static void _call_redn_wrapper_doneReading_CkReductionMsg(void* impl_msg, void* impl_obj_void);
    
    static void _call_doneReading_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_doneReading_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void logging(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_logging_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_logging_CkReductionMsg() {
      static int epidx = reg_logging_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_logging(void (Main::*)(CkReductionMsg* impl_msg) ) {
      return idx_logging_CkReductionMsg();
    }


    
    static int logging(CkReductionMsg* impl_msg) { return idx_logging_CkReductionMsg(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_logging_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_logging_CkReductionMsg() {
      static int epidx = reg_redn_wrapper_logging_CkReductionMsg();
      return epidx;
    }
    
    static int redn_wrapper_logging(CkReductionMsg* impl_msg) { return idx_redn_wrapper_logging_CkReductionMsg(); }
    
    static void _call_redn_wrapper_logging_CkReductionMsg(void* impl_msg, void* impl_obj_void);
    
    static void _call_logging_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_logging_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void postClose(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_postClose_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_postClose_CkReductionMsg() {
      static int epidx = reg_postClose_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_postClose(void (Main::*)(CkReductionMsg* impl_msg) ) {
      return idx_postClose_CkReductionMsg();
    }


    
    static int postClose(CkReductionMsg* impl_msg) { return idx_postClose_CkReductionMsg(); }
    
    static void _call_postClose_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_postClose_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void decrementCount();
     */
    // Entry point registration at startup
    
    static int reg_decrementCount_void();
    // Entry point index lookup
    
    inline static int idx_decrementCount_void() {
      static int epidx = reg_decrementCount_void();
      return epidx;
    }

    
    inline static int idx_decrementCount(void (Main::*)() ) {
      return idx_decrementCount_void();
    }


    
    static int decrementCount() { return idx_decrementCount_void(); }
    
    static void _call_decrementCount_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_decrementCount_void(void* impl_msg, void* impl_obj);
    /* DECLS: void startReading();
     */
    // Entry point registration at startup
    
    static int reg_startReading_void();
    // Entry point index lookup
    
    inline static int idx_startReading_void() {
      static int epidx = reg_startReading_void();
      return epidx;
    }

    
    inline static int idx_startReading(void (Main::*)() ) {
      return idx_startReading_void();
    }


    
    static int startReading() { return idx_startReading_void(); }
    
    static void _call_startReading_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_startReading_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
class CProxy_Main:public CProxy_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    CProxy_Main(void) {};
    CProxy_Main(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Main(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Main *ckLocal(void) const
    { return (Main *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);

/* DECLS: void ready(Ck::IO::FileReadyMsg* impl_msg);
 */
    
    void ready(Ck::IO::FileReadyMsg* impl_msg);

/* DECLS: void startRead(Ck::IO::SessionReadyMsg* impl_msg);
 */
    
    void startRead(Ck::IO::SessionReadyMsg* impl_msg);

/* DECLS: void doneReading(CkReductionMsg* impl_msg);
 */
    
    void doneReading(CkReductionMsg* impl_msg);

/* DECLS: void logging(CkReductionMsg* impl_msg);
 */
    
    void logging(CkReductionMsg* impl_msg);

/* DECLS: void postClose(CkReductionMsg* impl_msg);
 */
    
    void postClose(CkReductionMsg* impl_msg);

/* DECLS: void decrementCount();
 */
    
    void decrementCount(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void startReading();
 */
    
    void startReading(const CkEntryOptions *impl_e_opts=NULL);

};
#define Main_SDAG_CODE                                                         \
public:                                                                        \
  void postClose(CkReductionMsg msg);                                          \
  void postClose(CkReductionMsg* gen0);                                        \
private:                                                                       \
  void postClose_end(CkReductionMsg* gen0);                                    \
  void _slist_0(CkReductionMsg* gen0);                                         \
  void _slist_0_end(CkReductionMsg* gen0);                                     \
  void _serial_0(CkReductionMsg* gen0);                                        \
public:                                                                        \
  void decrementCount();                                                       \
private:                                                                       \
  void decrementCount_end();                                                   \
  void _slist_1();                                                             \
  void _slist_1_end();                                                         \
  void _serial_1();                                                            \
public:                                                                        \
  void startReading();                                                         \
  void _sdag_fnc_startReading();                                               \
private:                                                                       \
  void startReading_end();                                                     \
  void _slist_2();                                                             \
  void _slist_2_end();                                                         \
  void _serial_2();                                                            \
  SDAG::Continuation* _when_0();                                               \
  SDAG::Continuation* _when_0(int refnum_0);                                   \
  void _when_0_end(Ck::IO::FileReadyMsg* gen0);                                \
  void _serial_3(Ck::IO::FileReadyMsg* gen0);                                  \
  SDAG::Continuation* _when_1();                                               \
  SDAG::Continuation* _when_1(int refnum_0);                                   \
  void _when_1_end(Ck::IO::SessionReadyMsg* gen0);                             \
  void _serial_4(Ck::IO::SessionReadyMsg* gen0);                               \
public:                                                                        \
  void ready(Ck::IO::FileReadyMsg* msg_msg);                                   \
  void startRead(Ck::IO::SessionReadyMsg* msg_msg);                            \
public:                                                                        \
  SDAG::dep_ptr __dep;                                                         \
  void _sdag_init();                                                           \
  void __sdag_init();                                                          \
public:                                                                        \
  void _sdag_pup(PUP::er &p);                                                  \
  void __sdag_pup(PUP::er &p) { }                                              \
  static void __sdag_register();                                               \
  static int _sdag_idx_Main_serial_0();                                        \
  static int _sdag_reg_Main_serial_0();                                        \
  static int _sdag_idx_Main_serial_1();                                        \
  static int _sdag_reg_Main_serial_1();                                        \
  static int _sdag_idx_Main_serial_2();                                        \
  static int _sdag_reg_Main_serial_2();                                        \
  static int _sdag_idx_Main_serial_3();                                        \
  static int _sdag_reg_Main_serial_3();                                        \
  static int _sdag_idx_Main_serial_4();                                        \
  static int _sdag_reg_Main_serial_4();                                        \

typedef CBaseT1<Chare, CProxy_Main>CBase_Main;

/* DECLS: array Reader: ArrayElement{
Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
void verify(const std::string &test_file);
void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
Reader(CkMigrateMessage* impl_msg);
};
 */
 class Reader;
 class CkIndex_Reader;
 class CProxy_Reader;
 class CProxyElement_Reader;
 class CProxySection_Reader;
/* --------------- index object ------------------ */
class CkIndex_Reader:public CkIndex_ArrayElement{
  public:
    typedef Reader local_t;
    typedef CkIndex_Reader index_t;
    typedef CProxy_Reader proxy_t;
    typedef CProxyElement_Reader element_t;
    typedef CProxySection_Reader section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
     */
    // Entry point registration at startup
    
    static int reg_Reader_marshall1();
    // Entry point index lookup
    
    inline static int idx_Reader_marshall1() {
      static int epidx = reg_Reader_marshall1();
      return epidx;
    }

    
    static int ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares) { return idx_Reader_marshall1(); }
    
    static void _call_Reader_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Reader_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Reader_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Reader_marshall1(PUP::er &p,void *msg);
    /* DECLS: void verify(const std::string &test_file);
     */
    // Entry point registration at startup
    
    static int reg_verify_marshall2();
    // Entry point index lookup
    
    inline static int idx_verify_marshall2() {
      static int epidx = reg_verify_marshall2();
      return epidx;
    }

    
    inline static int idx_verify(void (Reader::*)(const std::string &test_file) ) {
      return idx_verify_marshall2();
    }


    
    static int verify(const std::string &test_file) { return idx_verify_marshall2(); }
    
    static void _call_verify_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_verify_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_verify_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_verify_marshall2(PUP::er &p,void *msg);
    /* DECLS: void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_testRead_ReadCompleteMsg();
    // Entry point index lookup
    
    inline static int idx_testRead_ReadCompleteMsg() {
      static int epidx = reg_testRead_ReadCompleteMsg();
      return epidx;
    }

    
    inline static int idx_testRead(void (Reader::*)(Ck::IO::ReadCompleteMsg* impl_msg) ) {
      return idx_testRead_ReadCompleteMsg();
    }


    
    static int testRead(Ck::IO::ReadCompleteMsg* impl_msg) { return idx_testRead_ReadCompleteMsg(); }
    
    static void _call_testRead_ReadCompleteMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_testRead_ReadCompleteMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
     */
    // Entry point registration at startup
    
    static int reg_verifyFullFileRead_marshall4();
    // Entry point index lookup
    
    inline static int idx_verifyFullFileRead_marshall4() {
      static int epidx = reg_verifyFullFileRead_marshall4();
      return epidx;
    }

    
    inline static int idx_verifyFullFileRead(void (Reader::*)(const std::string &test_file, const size_t &file_size, const size_t &num_chares) ) {
      return idx_verifyFullFileRead_marshall4();
    }


    
    static int verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares) { return idx_verifyFullFileRead_marshall4(); }
    
    static void _call_verifyFullFileRead_marshall4(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_verifyFullFileRead_marshall4(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_verifyFullFileRead_marshall4(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_verifyFullFileRead_marshall4(PUP::er &p,void *msg);
    /* DECLS: Reader(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Reader_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Reader_CkMigrateMessage() {
      static int epidx = reg_Reader_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Reader_CkMigrateMessage(); }
    
    static void _call_Reader_CkMigrateMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Reader_CkMigrateMessage(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Reader : public CProxyElement_ArrayElement{
  public:
    typedef Reader local_t;
    typedef CkIndex_Reader index_t;
    typedef CProxy_Reader proxy_t;
    typedef CProxyElement_Reader element_t;
    typedef CProxySection_Reader section_t;

    using array_index_t = CkArrayIndex1D;

    /* TRAM aggregators */

    CProxyElement_Reader(void) {
    }
    CProxyElement_Reader(const ArrayElement *e) : CProxyElement_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxyElement_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Reader *ckLocal(void) const
    { return (Reader *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Reader(const CkArrayID &aid,const CkArrayIndex1D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Reader(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}

    CProxyElement_Reader(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Reader(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}
/* DECLS: Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
 */
    
    void insert(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, int onPE=-1, const CkEntryOptions *impl_e_opts=NULL);
/* DECLS: void verify(const std::string &test_file);
 */
    
    void verify(const std::string &test_file, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
 */
    
    void testRead(Ck::IO::ReadCompleteMsg* impl_msg) ;

/* DECLS: void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
 */
    
    void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Reader(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- collective proxy -------------- */
 class CProxy_Reader : public CProxy_ArrayElement{
  public:
    typedef Reader local_t;
    typedef CkIndex_Reader index_t;
    typedef CProxy_Reader proxy_t;
    typedef CProxyElement_Reader element_t;
    typedef CProxySection_Reader section_t;

    using array_index_t = CkArrayIndex1D;
    CProxy_Reader(void) {
    }
    CProxy_Reader(const ArrayElement *e) : CProxy_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxy_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxy_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    // Empty array construction
    static CkArrayID ckNew(CkArrayOptions opts = CkArrayOptions()) { return ckCreateEmptyArray(opts); }
    static void      ckNew(CkCallback cb, CkArrayOptions opts = CkArrayOptions()) { ckCreateEmptyArrayAsync(cb, opts); }

    // Generalized array indexing:
    CProxyElement_Reader operator [] (const CkArrayIndex1D &idx) const
    { return CProxyElement_Reader(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Reader operator() (const CkArrayIndex1D &idx) const
    { return CProxyElement_Reader(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Reader operator [] (int idx) const 
        {return CProxyElement_Reader(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxyElement_Reader operator () (int idx) const 
        {return CProxyElement_Reader(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxy_Reader(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Reader(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
 */
    
    static CkArrayID ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, const CkArrayOptions &opts = CkArrayOptions(), const CkEntryOptions *impl_e_opts=NULL);
    static void      ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);
    static CkArrayID ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, const int s1, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void verify(const std::string &test_file);
 */
    
    void verify(const std::string &test_file, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
 */
    
    void testRead(Ck::IO::ReadCompleteMsg* impl_msg) ;

/* DECLS: void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
 */
    
    void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Reader(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- section proxy -------------- */
 class CProxySection_Reader : public CProxySection_ArrayElement{
  public:
    typedef Reader local_t;
    typedef CkIndex_Reader index_t;
    typedef CProxy_Reader proxy_t;
    typedef CProxyElement_Reader element_t;
    typedef CProxySection_Reader section_t;

    using array_index_t = CkArrayIndex1D;
    CProxySection_Reader(void) {
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxySection_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxySection_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Reader operator [] (const CkArrayIndex1D &idx) const
        {return CProxyElement_Reader(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Reader operator() (const CkArrayIndex1D &idx) const
        {return CProxyElement_Reader(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Reader operator [] (int idx) const 
        {return CProxyElement_Reader(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    CProxyElement_Reader operator () (int idx) const 
        {return CProxyElement_Reader(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex1D> &elems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      std::vector<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.emplace_back(i);
      return CkSectionID(aid, al, factor);
    } 
    CProxySection_Reader(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Reader(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,CK_DELCTOR_ARGS) {}
    CProxySection_Reader(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems,nElems, factor) {}
    CProxySection_Reader(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems, factor) { ckAutoDelegate(); }
    CProxySection_Reader(const CkSectionID &sid)  
        :CProxySection_ArrayElement(sid) { ckAutoDelegate(); }
    CProxySection_Reader(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Reader(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,CK_DELCTOR_ARGS) {}
    CProxySection_Reader(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) { ckAutoDelegate(); }
    CProxySection_Reader(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems) 
        :CProxySection_ArrayElement(aid,elems) { ckAutoDelegate(); }
    CProxySection_Reader(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, int factor) 
        :CProxySection_ArrayElement(n,aid,elems,nElems, factor) { ckAutoDelegate(); }
    CProxySection_Reader(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems, int factor) 
        :CProxySection_ArrayElement(aid,elems, factor) { ckAutoDelegate(); }
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems) {
       return CkSectionID(aid, elems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, int factor) {
      return CkSectionID(aid, elems, factor);
    } 
    void ckAutoDelegate(int opts=1) {
      if(ckIsDelegated()) return;
      CProxySection_ArrayElement::ckAutoDelegate(opts);
    } 
    void setReductionClient(CkCallback *cb) {
      CProxySection_ArrayElement::setReductionClient(cb);
    } 
    void resetSection() {
      CProxySection_ArrayElement::resetSection();
    } 
    static void contribute(CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    template <typename T>
    static void contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
    template <typename T>
    static void contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
/* DECLS: Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
 */
    

/* DECLS: void verify(const std::string &test_file);
 */
    
    void verify(const std::string &test_file, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
 */
    
    void testRead(Ck::IO::ReadCompleteMsg* impl_msg) ;

/* DECLS: void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
 */
    
    void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Reader(CkMigrateMessage* impl_msg);
 */

};
#define Reader_SDAG_CODE                                                       \
public:                                                                        \
  void testRead(Ck::IO::ReadCompleteMsg msg);                                  \
  void testRead(Ck::IO::ReadCompleteMsg* gen0);                                \
private:                                                                       \
  void testRead_end(Ck::IO::ReadCompleteMsg* gen0);                            \
  void _slist_0(Ck::IO::ReadCompleteMsg* gen0);                                \
  void _slist_0_end(Ck::IO::ReadCompleteMsg* gen0);                            \
  void _serial_0(Ck::IO::ReadCompleteMsg* gen0);                               \
public:                                                                        \
public:                                                                        \
  SDAG::dep_ptr __dep;                                                         \
  void _sdag_init();                                                           \
  void __sdag_init();                                                          \
public:                                                                        \
  void _sdag_pup(PUP::er &p);                                                  \
  void __sdag_pup(PUP::er &p) { }                                              \
  static void __sdag_register();                                               \
  static int _sdag_idx_Reader_serial_0();                                      \
  static int _sdag_reg_Reader_serial_0();                                      \

typedef CBaseT1<ArrayElementT<CkIndex1D>, CProxy_Reader>CBase_Reader;



/* ---------------- method closures -------------- */
class Closure_Main {
  public:







    struct decrementCount_7_closure;


    struct startReading_8_closure;

};

/* ---------------- method closures -------------- */
class Closure_Reader {
  public:


    struct verify_2_closure;



    struct verifyFullFileRead_4_closure;


};

extern void _registeriotest(void);
extern "C" void CkRegisterMainModule(void);
#endif
