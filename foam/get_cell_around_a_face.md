Knowing the internal face label (how to actually get that?) we can get to the owner
and neighbor cells labels

```cpp
label ownerCell = mesh.faceOwner()[faceLabel];
label neighbourCell = mesh.faceNeighbour()[faceLabel];

const vectorField& UInternal = U.internalField();
vector UOwner(UInternal[ownerCell);
vector UNeighb(UInternal[ownerNeighbour]);
```


## References

- [polyMesh::faceNeighbour()](https://www.openfoam.com/documentation/guides/latest/api/classFoam_1_1polyMesh.html#a9fb57b52c700ed61f09ada65412d13e3)

- [polyMesh::faceOwner()](https://www.openfoam.com/documentation/guides/latest/api/classFoam_1_1polyMesh.html#a57752b49bfee23ca1944c3fb0493974f)


