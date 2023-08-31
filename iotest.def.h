

/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::decrementCount_7_closure : public SDAG::Closure {
      

      decrementCount_7_closure() {
        init();
      }
      decrementCount_7_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~decrementCount_7_closure() {
      }
      PUPable_decl(SINGLE_ARG(decrementCount_7_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::startReading_8_closure : public SDAG::Closure {
      

      startReading_8_closure() {
        init();
      }
      startReading_8_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~startReading_8_closure() {
      }
      PUPable_decl(SINGLE_ARG(startReading_8_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Reader::verify_2_closure : public SDAG::Closure {
            std::string test_file;


      verify_2_closure() {
        init();
      }
      verify_2_closure(CkMigrateMessage*) {
        init();
      }
            std::string & getP0() { return test_file;}
      void pup(PUP::er& __p) {
        __p | test_file;
        packClosure(__p);
      }
      virtual ~verify_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(verify_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Reader::verifyFullFileRead_4_closure : public SDAG::Closure {
            std::string test_file;
            size_t file_size;
            size_t num_chares;


      verifyFullFileRead_4_closure() {
        init();
      }
      verifyFullFileRead_4_closure(CkMigrateMessage*) {
        init();
      }
            std::string & getP0() { return test_file;}
            size_t & getP1() { return file_size;}
            size_t & getP2() { return num_chares;}
      void pup(PUP::er& __p) {
        __p | test_file;
        __p | file_size;
        __p | num_chares;
        packClosure(__p);
      }
      virtual ~verifyFullFileRead_4_closure() {
      }
      PUPable_decl(SINGLE_ARG(verifyFullFileRead_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */



/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Main: Chare{
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
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */
CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Main_CkArgMsg), CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ready(Ck::IO::FileReadyMsg* impl_msg);
 */
void CProxy_Main::ready(Ck::IO::FileReadyMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_ready_FileReadyMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_ready_FileReadyMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_ready_FileReadyMsg(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_ready_FileReadyMsg() {
  int epidx = CkRegisterEp("ready(Ck::IO::FileReadyMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_ready_FileReadyMsg), Ck::IO::CMessage_FileReadyMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)Ck::IO::FileReadyMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_ready_FileReadyMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->ready((Ck::IO::FileReadyMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void startRead(Ck::IO::SessionReadyMsg* impl_msg);
 */
void CProxy_Main::startRead(Ck::IO::SessionReadyMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_startRead_SessionReadyMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_startRead_SessionReadyMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_startRead_SessionReadyMsg(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_startRead_SessionReadyMsg() {
  int epidx = CkRegisterEp("startRead(Ck::IO::SessionReadyMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_startRead_SessionReadyMsg), Ck::IO::CMessage_SessionReadyMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)Ck::IO::SessionReadyMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_startRead_SessionReadyMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->startRead((Ck::IO::SessionReadyMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void doneReading(CkReductionMsg* impl_msg);
 */
void CProxy_Main::doneReading(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_doneReading_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_doneReading_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_doneReading_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
  }
}
void CkIndex_Main::_call_redn_wrapper_doneReading_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  impl_obj->doneReading((CkReductionMsg*)impl_msg);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function
int CkIndex_Main::reg_doneReading_CkReductionMsg() {
  int epidx = CkRegisterEp("doneReading(CkReductionMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_doneReading_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}


// Redn wrapper registration function
int CkIndex_Main::reg_redn_wrapper_doneReading_CkReductionMsg() {
  return CkRegisterEp("redn_wrapper_doneReading(CkReductionMsg *impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_redn_wrapper_doneReading_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
}

void CkIndex_Main::_call_doneReading_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->doneReading((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void logging(CkReductionMsg* impl_msg);
 */
void CProxy_Main::logging(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_logging_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_logging_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_logging_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
  }
}
void CkIndex_Main::_call_redn_wrapper_logging_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  impl_obj->logging((CkReductionMsg*)impl_msg);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function
int CkIndex_Main::reg_logging_CkReductionMsg() {
  int epidx = CkRegisterEp("logging(CkReductionMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_logging_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}


// Redn wrapper registration function
int CkIndex_Main::reg_redn_wrapper_logging_CkReductionMsg() {
  return CkRegisterEp("redn_wrapper_logging(CkReductionMsg *impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_redn_wrapper_logging_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
}

void CkIndex_Main::_call_logging_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->logging((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void postClose(CkReductionMsg* impl_msg);
 */
void CProxy_Main::postClose(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_postClose_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_postClose_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_postClose_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_postClose_CkReductionMsg() {
  int epidx = CkRegisterEp("postClose(CkReductionMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_postClose_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_postClose_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->postClose((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void decrementCount();
 */
void CProxy_Main::decrementCount(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_decrementCount_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_decrementCount_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_decrementCount_void(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_decrementCount_void() {
  int epidx = CkRegisterEp("decrementCount()",
      reinterpret_cast<CkCallFnPtr>(_call_decrementCount_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Main::_call_decrementCount_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->decrementCount();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::decrementCount_7_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void startReading();
 */
void CProxy_Main::startReading(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_startReading_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_startReading_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_startReading_void(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_startReading_void() {
  int epidx = CkRegisterEp("startReading()",
      reinterpret_cast<CkCallFnPtr>(_call_startReading_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Main::_call_startReading_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->_sdag_fnc_startReading();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::startReading_8_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void ready(Ck::IO::FileReadyMsg* impl_msg);
  idx_ready_FileReadyMsg();

  // REG: void startRead(Ck::IO::SessionReadyMsg* impl_msg);
  idx_startRead_SessionReadyMsg();

  // REG: void doneReading(CkReductionMsg* impl_msg);
  idx_doneReading_CkReductionMsg();
  idx_redn_wrapper_doneReading_CkReductionMsg();

  // REG: void logging(CkReductionMsg* impl_msg);
  idx_logging_CkReductionMsg();
  idx_redn_wrapper_logging_CkReductionMsg();

  // REG: void postClose(CkReductionMsg* impl_msg);
  idx_postClose_CkReductionMsg();

  // REG: void decrementCount();
  idx_decrementCount_void();

  // REG: void startReading();
  idx_startReading_void();

  Main::__sdag_register(); // Potentially missing Main_SDAG_CODE in your class definition?
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void Main::postClose(CkReductionMsg* gen0) {
  _TRACE_END_EXECUTE(); 
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(gen0);
  _slist_0(gen0);
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::postClose_end(CkReductionMsg* gen0) {
  CmiFree(UsrToEnv(gen0));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_0(CkReductionMsg* gen0) {
  _serial_0(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_0_end(CkReductionMsg* gen0) {
  postClose_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_0(CkReductionMsg* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_0()), CkMyPe(), 0, NULL, this); 
  {
    CkReductionMsg*& msg = gen0;
    { // begin serial block
#line 11 "iotest.ci"

    ckout << "Entered the postClose function\n";
    CkExit();
   
#line 502 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _slist_0_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::decrementCount() {
  _TRACE_END_EXECUTE(); 
  if (!__dep.get()) _sdag_init();
  _slist_1();
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::decrementCount_end() {
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_1() {
  _serial_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_1_end() {
  decrementCount_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_1() {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_1()), CkMyPe(), 0, NULL, this); 
  { // begin serial block
#line 17 "iotest.ci"

    num_reads_done--;
    ckout << "decremented the count to " << num_reads_done << endl;
    if(!num_reads_done){
     CkCallback cb(CkIndex_Main::postClose(0), thisProxy);
     std::cout << "About to enter closing session\n";
     Ck::IO::closeReadSession(current_session, cb);
    }
   
#line 555 "iotest.def.h"
  } // end serial block
  _TRACE_END_EXECUTE(); 
  _slist_1_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::startReading(){
  CkPrintf("Error> Direct call to SDAG entry method \'%s::%s\'!\n", "Main", "startReading()"); 
  CkAbort("Direct SDAG call is not allowed for SDAG entry methods having when constructs. Call such SDAG methods using a proxy"); 
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::_sdag_fnc_startReading() {
  _TRACE_END_EXECUTE(); 
  if (!__dep.get()) _sdag_init();
  _slist_2();
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::startReading_end() {
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_2() {
  _serial_2();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_2_end() {
  startReading_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_2() {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_2()), CkMyPe(), 0, NULL, this); 
  { // begin serial block
#line 28 "iotest.ci"

    Ck::IO::Options opts;
    opts.numReaders = num_io_buffers;
    CkCallback open_cb(CkIndex_Main::ready(NULL), thisProxy);
    open_cb.setRefNum(0);
    start_time = CkWallTimer();
    Ck::IO::open(TEST_FILE, open_cb, opts);
   
#line 613 "iotest.def.h"
  } // end serial block
  _TRACE_END_EXECUTE(); 
  _when_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_0() {
  CMK_REFNUM_TYPE refnum_0;
  {
    refnum_0 = 0;
  }
  return _when_0(refnum_0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_0(int refnum_0) {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(0, true, refnum_0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_3(static_cast<Ck::IO::FileReadyMsg*>(static_cast<SDAG::MsgClosure*>(buf0->cl)->msg));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(0);
    c->entries.push_back(0);
    c->refnums.push_back(refnum_0);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_0_end(Ck::IO::FileReadyMsg* gen0) {
  {
    Ck::IO::FileReadyMsg*& msg = gen0;
    CmiFree(UsrToEnv(msg));
  }
  _when_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_3(Ck::IO::FileReadyMsg* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_3()), CkMyPe(), 0, NULL, this); 
  {
    Ck::IO::FileReadyMsg*& msg = gen0;
    { // begin serial block
#line 36 "iotest.ci"

     _file = msg -> file;
     CkCallback start_read_session(CkIndex_Main::startRead(NULL), thisProxy);
     start_read_session.setRefNum(0);
     Ck::IO::startReadSession(_file, file_size, 0, start_read_session );
   
#line 675 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _when_0_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_1() {
  CMK_REFNUM_TYPE refnum_0;
  {
    refnum_0 = 0;
  }
  return _when_1(refnum_0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_1(int refnum_0) {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(1, true, refnum_0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_4(static_cast<Ck::IO::SessionReadyMsg*>(static_cast<SDAG::MsgClosure*>(buf0->cl)->msg));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(1);
    c->entries.push_back(1);
    c->refnums.push_back(refnum_0);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_1_end(Ck::IO::SessionReadyMsg* gen0) {
  {
    Ck::IO::SessionReadyMsg*& msg = gen0;
    CmiFree(UsrToEnv(msg));
  }
  _slist_2_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_4(Ck::IO::SessionReadyMsg* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_4()), CkMyPe(), 0, NULL, this); 
  {
    Ck::IO::SessionReadyMsg*& msg = gen0;
    { // begin serial block
#line 42 "iotest.ci"

    CkPrintf("The read session has been set up. Moving on to the reads\n");
    current_session = msg -> session;
    CkCallback test_read_cb(CkIndex_Reader::testRead(0), thisProxy);
        CkPrintf("file size is %zu\n",file_size);
    readers = CProxy_Reader::ckNew(msg -> session, file_size, file_size / num_readers, 0, num_readers, num_readers);
   
#line 739 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _when_1_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::ready(Ck::IO::FileReadyMsg* msg_msg){
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(msg_msg);
  __dep->pushBuffer(0, new SDAG::MsgClosure(msg_msg));
  SDAG::Continuation* c = __dep->tryFindContinuation(0);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_0(
      c->refnums[0]
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::startRead(Ck::IO::SessionReadyMsg* msg_msg){
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(msg_msg);
  __dep->pushBuffer(1, new SDAG::MsgClosure(msg_msg));
  SDAG::Continuation* c = __dep->tryFindContinuation(1);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_1(
      c->refnums[0]
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::_sdag_init() { // Potentially missing Main_SDAG_CODE in your class definition?
  __dep.reset(new SDAG::Dependency(2,2));
  __dep->addDepends(0,0);
  __dep->addDepends(1,1);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::__sdag_init() { // Potentially missing Main_SDAG_CODE in your class definition?
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_sdag_pup(PUP::er &p) {  // Potentially missing Main_SDAG_CODE in your class definition?
  p|__dep;
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::__sdag_register() { // Potentially missing Main_SDAG_CODE in your class definition?
  (void)_sdag_idx_Main_serial_0();
  (void)_sdag_idx_Main_serial_1();
  (void)_sdag_idx_Main_serial_2();
  (void)_sdag_idx_Main_serial_3();
  (void)_sdag_idx_Main_serial_4();
  PUPable_reg(SINGLE_ARG(Closure_Main::decrementCount_7_closure));
  PUPable_reg(SINGLE_ARG(Closure_Main::startReading_8_closure));
  PUPable_reg(SINGLE_ARG(Closure_Main::decrementCount_7_closure));
  PUPable_reg(SINGLE_ARG(Closure_Main::startReading_8_closure));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_0() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_0();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_0() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_0", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_1() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_1();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_1() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_1", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_2() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_2();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_2() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_2", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_3() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_3();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_3() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_3", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_4() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_4();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_4() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_4", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */



/* DEFS: array Reader: ArrayElement{
Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
void verify(const std::string &test_file);
void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
Reader(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Reader::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_Reader::contribute(CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, userData, fragSize);
}

void CProxySection_Reader::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template <typename T>
void CProxySection_Reader::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, userData, fragSize);
}

void CProxySection_Reader::contribute(CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, cb, userData, fragSize);
}

void CProxySection_Reader::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

template <typename T>
void CProxySection_Reader::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
 */
void CProxyElement_Reader::insert(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, int onPE, const CkEntryOptions *impl_e_opts)
{ 
   //Marshall: const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
  }
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Reader::idx_Reader_marshall1(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void verify(const std::string &test_file);
 */
void CProxyElement_Reader::verify(const std::string &test_file, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &test_file
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Reader::idx_verify_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
 */
void CProxyElement_Reader::testRead(Ck::IO::ReadCompleteMsg* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Reader::idx_testRead_ReadCompleteMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
 */
void CProxyElement_Reader::verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &test_file, const size_t &file_size, const size_t &num_chares
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Reader::idx_verifyFullFileRead_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Reader(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
 */
CkArrayID CProxy_Reader::ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Reader::idx_Reader_marshall1(), opts);
  return gId;
}
void CProxy_Reader::ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Reader::idx_Reader_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}
CkArrayID CProxy_Reader::ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, const int s1, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Reader::idx_Reader_marshall1(), opts);
  return gId;
}
void CProxy_Reader::ckNew(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)session;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytes;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)offsets;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Reader::idx_Reader_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
int CkIndex_Reader::reg_Reader_marshall1() {
  int epidx = CkRegisterEp("Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares)",
      reinterpret_cast<CkCallFnPtr>(_call_Reader_marshall1), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Reader_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Reader_marshall1);

  return epidx;
}

void CkIndex_Reader::_call_Reader_marshall1(void* impl_msg, void* impl_obj_void)
{
  Reader* impl_obj = static_cast<Reader*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<Ck::IO::Session> session;
  implP|session;
  PUP::detail::TemporaryObjectHolder<size_t> file_size;
  implP|file_size;
  PUP::detail::TemporaryObjectHolder<size_t> bytes;
  implP|bytes;
  PUP::detail::TemporaryObjectHolder<size_t> offsets;
  implP|offsets;
  PUP::detail::TemporaryObjectHolder<size_t> num_chares;
  implP|num_chares;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Reader(std::move(session.t), std::move(file_size.t), std::move(bytes.t), std::move(offsets.t), std::move(num_chares.t));
}
int CkIndex_Reader::_callmarshall_Reader_marshall1(char* impl_buf, void* impl_obj_void) {
  Reader* impl_obj = static_cast<Reader*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<Ck::IO::Session> session;
  implP|session;
  PUP::detail::TemporaryObjectHolder<size_t> file_size;
  implP|file_size;
  PUP::detail::TemporaryObjectHolder<size_t> bytes;
  implP|bytes;
  PUP::detail::TemporaryObjectHolder<size_t> offsets;
  implP|offsets;
  PUP::detail::TemporaryObjectHolder<size_t> num_chares;
  implP|num_chares;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Reader(std::move(session.t), std::move(file_size.t), std::move(bytes.t), std::move(offsets.t), std::move(num_chares.t));
  return implP.size();
}
void CkIndex_Reader::_marshallmessagepup_Reader_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<Ck::IO::Session> session;
  implP|session;
  PUP::detail::TemporaryObjectHolder<size_t> file_size;
  implP|file_size;
  PUP::detail::TemporaryObjectHolder<size_t> bytes;
  implP|bytes;
  PUP::detail::TemporaryObjectHolder<size_t> offsets;
  implP|offsets;
  PUP::detail::TemporaryObjectHolder<size_t> num_chares;
  implP|num_chares;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("session");
  implDestP|session;
  if (implDestP.hasComments()) implDestP.comment("file_size");
  implDestP|file_size;
  if (implDestP.hasComments()) implDestP.comment("bytes");
  implDestP|bytes;
  if (implDestP.hasComments()) implDestP.comment("offsets");
  implDestP|offsets;
  if (implDestP.hasComments()) implDestP.comment("num_chares");
  implDestP|num_chares;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void verify(const std::string &test_file);
 */
void CProxy_Reader::verify(const std::string &test_file, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &test_file
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Reader::idx_verify_marshall2(),0);
}

// Entry point registration function
int CkIndex_Reader::reg_verify_marshall2() {
  int epidx = CkRegisterEp("verify(const std::string &test_file)",
      reinterpret_cast<CkCallFnPtr>(_call_verify_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_verify_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_verify_marshall2);

  return epidx;
}

void CkIndex_Reader::_call_verify_marshall2(void* impl_msg, void* impl_obj_void)
{
  Reader* impl_obj = static_cast<Reader*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::string &test_file*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> test_file;
  implP|test_file;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->verify(std::move(test_file.t));
}
int CkIndex_Reader::_callmarshall_verify_marshall2(char* impl_buf, void* impl_obj_void) {
  Reader* impl_obj = static_cast<Reader*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const std::string &test_file*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> test_file;
  implP|test_file;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->verify(std::move(test_file.t));
  return implP.size();
}
void CkIndex_Reader::_marshallmessagepup_verify_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::string &test_file*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> test_file;
  implP|test_file;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("test_file");
  implDestP|test_file;
}
PUPable_def(SINGLE_ARG(Closure_Reader::verify_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
 */
void CProxy_Reader::testRead(Ck::IO::ReadCompleteMsg* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Reader::idx_testRead_ReadCompleteMsg(),0);
}

// Entry point registration function
int CkIndex_Reader::reg_testRead_ReadCompleteMsg() {
  int epidx = CkRegisterEp("testRead(Ck::IO::ReadCompleteMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_testRead_ReadCompleteMsg), Ck::IO::CMessage_ReadCompleteMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)Ck::IO::ReadCompleteMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Reader::_call_testRead_ReadCompleteMsg(void* impl_msg, void* impl_obj_void)
{
  Reader* impl_obj = static_cast<Reader*>(impl_obj_void);
  impl_obj->testRead((Ck::IO::ReadCompleteMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
 */
void CProxy_Reader::verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &test_file, const size_t &file_size, const size_t &num_chares
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Reader::idx_verifyFullFileRead_marshall4(),0);
}

// Entry point registration function
int CkIndex_Reader::reg_verifyFullFileRead_marshall4() {
  int epidx = CkRegisterEp("verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares)",
      reinterpret_cast<CkCallFnPtr>(_call_verifyFullFileRead_marshall4), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_verifyFullFileRead_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_verifyFullFileRead_marshall4);

  return epidx;
}

void CkIndex_Reader::_call_verifyFullFileRead_marshall4(void* impl_msg, void* impl_obj_void)
{
  Reader* impl_obj = static_cast<Reader*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::string &test_file, const size_t &file_size, const size_t &num_chares*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> test_file;
  implP|test_file;
  PUP::detail::TemporaryObjectHolder<size_t> file_size;
  implP|file_size;
  PUP::detail::TemporaryObjectHolder<size_t> num_chares;
  implP|num_chares;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->verifyFullFileRead(std::move(test_file.t), std::move(file_size.t), std::move(num_chares.t));
}
int CkIndex_Reader::_callmarshall_verifyFullFileRead_marshall4(char* impl_buf, void* impl_obj_void) {
  Reader* impl_obj = static_cast<Reader*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const std::string &test_file, const size_t &file_size, const size_t &num_chares*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> test_file;
  implP|test_file;
  PUP::detail::TemporaryObjectHolder<size_t> file_size;
  implP|file_size;
  PUP::detail::TemporaryObjectHolder<size_t> num_chares;
  implP|num_chares;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->verifyFullFileRead(std::move(test_file.t), std::move(file_size.t), std::move(num_chares.t));
  return implP.size();
}
void CkIndex_Reader::_marshallmessagepup_verifyFullFileRead_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::string &test_file, const size_t &file_size, const size_t &num_chares*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> test_file;
  implP|test_file;
  PUP::detail::TemporaryObjectHolder<size_t> file_size;
  implP|file_size;
  PUP::detail::TemporaryObjectHolder<size_t> num_chares;
  implP|num_chares;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("test_file");
  implDestP|test_file;
  if (implDestP.hasComments()) implDestP.comment("file_size");
  implDestP|file_size;
  if (implDestP.hasComments()) implDestP.comment("num_chares");
  implDestP|num_chares;
}
PUPable_def(SINGLE_ARG(Closure_Reader::verifyFullFileRead_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Reader(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
int CkIndex_Reader::reg_Reader_CkMigrateMessage() {
  int epidx = CkRegisterEp("Reader(CkMigrateMessage* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Reader_CkMigrateMessage), 0, __idx, 0);
  return epidx;
}

void CkIndex_Reader::_call_Reader_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<Reader> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void verify(const std::string &test_file);
 */
void CProxySection_Reader::verify(const std::string &test_file, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &test_file
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Reader::idx_verify_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
 */
void CProxySection_Reader::testRead(Ck::IO::ReadCompleteMsg* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Reader::idx_testRead_ReadCompleteMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
 */
void CProxySection_Reader::verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &test_file, const size_t &file_size, const size_t &num_chares
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)test_file;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)file_size;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)num_chares;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Reader::idx_verifyFullFileRead_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Reader(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Reader::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterArrayDimensions(__idx, 1);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
  idx_Reader_marshall1();

  // REG: void verify(const std::string &test_file);
  idx_verify_marshall2();

  // REG: void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
  idx_testRead_ReadCompleteMsg();

  // REG: void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
  idx_verifyFullFileRead_marshall4();

  // REG: Reader(CkMigrateMessage* impl_msg);
  idx_Reader_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Reader_CkMigrateMessage());

  Reader::__sdag_register(); // Potentially missing Reader_SDAG_CODE in your class definition?
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void Reader::testRead(Ck::IO::ReadCompleteMsg* gen0) {
  _TRACE_END_EXECUTE(); 
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(gen0);
  _slist_0(gen0);
  CmiObjId projID = this->ckGetArrayIndex().getProjectionID();
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, &projID, this); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Reader::testRead_end(Ck::IO::ReadCompleteMsg* gen0) {
  CmiFree(UsrToEnv(gen0));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Reader::_slist_0(Ck::IO::ReadCompleteMsg* gen0) {
  _serial_0(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Reader::_slist_0_end(Ck::IO::ReadCompleteMsg* gen0) {
  testRead_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Reader::_serial_0(Ck::IO::ReadCompleteMsg* gen0) {
  CmiObjId projID = this->ckGetArrayIndex().getProjectionID();
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Reader_serial_0()), CkMyPe(), 0, &projID, this); 
  {
    Ck::IO::ReadCompleteMsg*& msg = gen0;
    { // begin serial block
#line 55 "iotest.ci"

    CkCallback cb(CkReductionTarget(Main, doneReading), mainProxy);
    size_t bytes = msg -> bytes;
    og_msg = msg;
    contribute(sizeof(bytes), &bytes, CkReduction::nop, cb);
   
#line 1685 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _slist_0_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Reader::_sdag_init() { // Potentially missing Reader_SDAG_CODE in your class definition?
  __dep.reset(new SDAG::Dependency(0,0));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Reader::__sdag_init() { // Potentially missing Reader_SDAG_CODE in your class definition?
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Reader::_sdag_pup(PUP::er &p) {  // Potentially missing Reader_SDAG_CODE in your class definition?
  p|__dep;
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Reader::__sdag_register() { // Potentially missing Reader_SDAG_CODE in your class definition?
  (void)_sdag_idx_Reader_serial_0();
  PUPable_reg(SINGLE_ARG(Closure_Reader::verify_2_closure));
  PUPable_reg(SINGLE_ARG(Closure_Reader::verifyFullFileRead_4_closure));
  PUPable_reg(SINGLE_ARG(Closure_Reader::verify_2_closure));
  PUPable_reg(SINGLE_ARG(Closure_Reader::verifyFullFileRead_4_closure));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Reader::_sdag_idx_Reader_serial_0() { // Potentially missing Reader_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Reader_serial_0();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Reader::_sdag_reg_Reader_serial_0() { // Potentially missing Reader_SDAG_CODE in your class definition?
  return CkRegisterEp("Reader_serial_0", NULL, 0, CkIndex_Reader::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */



#ifndef CK_TEMPLATES_ONLY
void _registeriotest(void)
{
  static int _done = 0; if(_done) return; _done = 1;

  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

/* REG: mainchare Main: Chare{
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
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Reader: ArrayElement{
Reader(const Ck::IO::Session &session, const size_t &file_size, const size_t &bytes, const size_t &offsets, const size_t &num_chares);
void verify(const std::string &test_file);
void testRead(Ck::IO::ReadCompleteMsg* impl_msg);
void verifyFullFileRead(const std::string &test_file, const size_t &file_size, const size_t &num_chares);
Reader(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Reader::__register("Reader", sizeof(Reader));

}
extern "C" void CkRegisterMainModule(void) {
  _registeriotest();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main>(dynamic_cast<Main*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Reader::virtual_pup(PUP::er &p) {
    recursive_pup<Reader>(dynamic_cast<Reader*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
