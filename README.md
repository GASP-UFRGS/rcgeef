# RCEEGF

Geant4 simulation to investigate the interaction of cosmic rays with components of our atmosphere.

## Instructions 

In order to run, you must have Geant4 installed. Create a 'build' directory:

`mkdir build`
`cd build`

Now you must load the Geant4 environemnt:

`source path_to/geant4.sh`

Then, you compile:

`cmake ../ && make`

For enabling the visualization, copý the files `vis.mac` and `init_vis.mac` to the `build` folder.

To run, type:

`./rceegf`
