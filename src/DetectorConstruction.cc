#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4VisAttributes.hh"
#include "G4Element.hh"
#include "G4Box.hh"
#include "G4UserLimits.hh"


// Constructor
DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(), logicWorld(0),physWorld(0), solidTarget(0),
logicTarget(0), physTarget(0), worldMaterial(0), targetMaterial(0), Air(0)
{
    DefineMaterials();
} 

// Destructor
DetectorConstruction::~DetectorConstruction(){

}

void DetectorConstruction::DefineMaterials(){
    
    // Get materials from NIST database
    G4NistManager* nist = G4NistManager::Instance();

    worldMaterial = nist->FindOrBuildMaterial("G4_Galactic");
    Air = nist->FindOrBuildMaterial("G4_AIR");
    targetMaterial = Air;

}

G4VPhysicalVolume* DetectorConstruction::Construct(){

    //World Geometry

    G4double halfsize_xy = 2.5*m;
    G4double halfsize_z = 3*m;

    G4Box* solidWorld = new G4Box("BoxWorld", halfsize_xy, halfsize_xy, halfsize_z);
    logicWorld = new G4LogicalVolume(solidWorld, worldMaterial,"logicWorld");
    physWorld = new G4PVPlacement(0,G4ThreeVector(), logicWorld, "World",0,false,0);

    // Target geometry 

    G4double halfSize_xy_target = halfsize_z;
    G4double halfsize_z_target = halfsize_z - 0.1*m; 
    solidTarget = new G4Box("BoxTarget", halfSize_xy_target, halfSize_xy_target, halfsize_z_target);
    logicTarget = new G4LogicalVolume(solidTarget, targetMaterial, "logicTarget");
    physTarget = new G4PVPlacement(0,
                                    G4ThreeVector(0,0,0),
                                    logicTarget,
                                    "PhysTarget",
                                    logicWorld,
                                    false,
                                    0,
                                    true);



    // World Visualization 
    G4VisAttributes* worldVis = new G4VisAttributes();
    worldVis->SetColor(0.1, 0.3, 0.8, 0.5);
    logicWorld->SetVisAttributes(worldVis);

    // Target Visualization
    G4VisAttributes* TargetVis = new G4VisAttributes();
    TargetVis->SetColor(0.1, 0.1, 0.1, 0.1);
    logicTarget->SetVisAttributes(TargetVis);

    return physWorld;

}

void DetectorConstruction::ConstructSDandField()
{

}

