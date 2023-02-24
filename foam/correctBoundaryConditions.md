correct boundary field


```cpp
template<class Type, template<class> class PatchField, class GeoMesh>
void Foam::GeometricField<Type, PatchField, GeoMesh>::
correctBoundaryConditions()
{
    /// set as up-to-date
    this->setUpToDate();

    /// Store the old-time field
    storeOldTimes();

    boundaryField_.evaluate();
}
```

- `setUpToDate()`

  ```
  void Foam::regIOobject::setUpToDate()
  {
      eventNo_ = db().getEvent();
  }
  ```


- `storeOldFields()`

  ```
    template<class Type, template<class> class PatchField, class GeoMesh>
  void Foam::GeometricField<Type, PatchField, GeoMesh>::storeOldTimes() const
  {
      if
      (
          // ptr to old time field
          field0Ptr_
          // timeIndex: current time index (used to trigger the storing of
          the old-time value)
       && timeIndex_ != this->time().timeIndex()
          // 
       && !this->name().ends_with("_0")
      )
      {
          storeOldTime();
          timeIndex_ = this->time().timeIndex();
      }
  }

  ```
