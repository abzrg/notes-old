# Particle tracking with ParaView and OpenFOAM

1. `foamToVTK` (for few time steps just to have the geometry)
2. Run `particleTracks` (create a file in the VTK folder)
3. Run ParaView and load the VTK group of files
4. Slice (it should be already on the middle; z-axis)
5. Load the particle track file
6. Change he aesthetics
  - thickness: 1.7
