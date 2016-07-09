#ifndef _AMC13_INTERFACE_H__
#define _AMC13_INTERFACE_H__

#include "amc13/AMC13.hh"
#include "PixelUtilities/PixeluTCAUtilities/include/PixelUhalLogSetter.h"

class PixelAMC13Interface {
 public:
  struct BGO {
    BGO() : fUse(false) {}
    BGO(uint32_t pCommand, bool enable, bool enableSingle, int pPrescale, int pBX)
    : fUse(true),
      fCommand(pCommand),
      isLong(fCommand & 0xFFFFFF00),
      fEnable(enable),
      fEnableSingle(enableSingle),
      fPrescale(pPrescale),
      fBX(pBX)
    {}

    bool fUse;
    unsigned fCommand;
    bool isLong;
    bool fEnable;
    bool fEnableSingle;
    unsigned fPrescale;
    unsigned fBX;
  };

  PixelAMC13Interface(const std::string& uriT1, const std::string& addressT1, const std::string& uriT2, const std::string& addressT2);
  ~PixelAMC13Interface();

  amc13::AMC13* Get() { return fAMC13; }

  void SetMask(uint32_t v) { fMask = v; }
  void SetMask(const std::string& v) { fMask = fAMC13->parseInputEnableList(v, true); }
  void SetSimTTC(bool v) { fSimTTC = v; }
  void SetDebugPrints(bool v) { fDebugPrints = v; }
  void SetCalBX(unsigned v) { fCalBX = v; }
  void SetL1ADelay(unsigned v) { fL1ADelay = v; }
  void SetNewWay(bool v) { fNewWay = v; }
  void SetVerifyL1A(bool v) { fVerifyL1A = v; }

  void DoResets();

  void Configure();
  void Halt();
  void Reset();

  void CalSync();
  void LevelOne();
  void ResetTBM();
  void ResetROC();
  void ResetCounters();

  uint32_t GetClockFreq();
  uint64_t GetL1ACount();
  uint32_t GetL1ARate();
  uint32_t GetT1Version();
  uint32_t GetT2Version();
  uint32_t GetSlotMask();
  bool GetTTCSimulator();

  uint64_t GetLevelOneCount();
  uint64_t GetCalSyncCount();
  uint64_t GetResetROCCount();
  uint64_t GetResetTBMCount();

  void ClearL1AHistory();
  void ClearTTCHistory();
  void ClearTTCHistoryFilter();
  uint32_t getTTCHistoryItemAddress( int item);
  void DumpHistory();
  void DumpTriggers();

  void ConfigureBGO(unsigned i, BGO b);
  void FireBGO(unsigned which);

 private:
  PixelUhalLogSetter logSetter;

  amc13::AMC13* fAMC13;
  uint32_t fMask;
  bool fSimTTC;
  bool fDebugPrints;
  uint32_t fCalBX;
  uint32_t fL1ADelay;
  bool fNewWay;

  bool fVerifyL1A;
  uint64_t previousL1ACount;
  int nL1ARetries;
  void VerifyL1ASetup();
  bool VerifyL1ACheck();

  uint64_t countLevelOne;
  uint64_t countCalSync;
  uint64_t countResetTBM;
  uint64_t countResetROC;
};

#endif
