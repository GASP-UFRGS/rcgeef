#ifndef Action_Initialization_h
#define Action_Initialization_h 1

#include "G4Version.hh"

#if (G4VERSION_NUMBER >= 1000)
#include "G4VUserActionInitialization.hh"


class ActionInitialization : public G4VUserActionInitialization {
public:
  ActionInitialization();
  ~ActionInitialization();

  virtual void Build() const;
  virtual void BuildForMaster() const;

private:
  
};

#endif
#endif