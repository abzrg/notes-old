# ParaView

## ParaView Paradigm

- read, filtering, rendering

## Primary data types in ParaView

- Uniform rectangular (Image data)
- Non-unifor rectangular (Rectangular grid)
- Curvilinear (Structured grid)
- Polygonal (Poly data)
- Unstructured grid

## User interface

- Menubar
  - access majority of features.
- Toolbars
  - quick access to most commonly used features.
- Pipeline browser
  - manage the reading and filtering of the data with a pipeline.
  - allows you to view the pipeline structure and select the pipeline object.
- Properties (+information) panel
  - view and change the parameters of the current pipeline object.
  - advanced properties toggle
  - information tab shows a basic summary of the data produced by the pipeline object.
- 3D view
  - initially a 3d view of the geometrical representation of the data.

## Sources

- Two ways to get data in ParaView:
  - read data from a file
  - generate data with a **source** object

- All sources are located in the `Sources` menu

- Example: Creating a Source
  - Sources > Geometric Shapes > Cylinder
  - click apply

## Basic 3D Interaction

- mouse clicking and draging manipulation. operations like:
  - rotate
  - zoom
  - pan
  - hold x, y, z while dragging to constraint movement along the x, y and z axis.
- Camera manipulation toolbars
  1. reset camera
    - same view direction but reposition the camera such that the entire object can be seen.
  1. zoom to data
    - similar to reset camera except that instead of positioning the camera to see all data, the camera is placed to look specifically at the data currently selected in the pipeline browser.
  1. reset camera closest
    - maximizes the occupation, in the screen, of the whole scene bounding box.
  1. zoom closest to data
    - It behaves very much like reset camera closest except that instead of positioning the camera to see all data, the camera is placed to look specifically at the data currently selected in the pipeline browser.
  1. rubber-band zoom (zoom to box)
    - allows you to select a rectangular region of the screen to zoom.
  1. set view direction to
    - +x, -x, +y, -y, +z, -z
  1. rotate 90 deg
    - cw
    - ccw
- Toolbar for controlling the location of the center of the rotation and the visibility of the orientation axes
  - center of rotation
  - reset center
  - show center
  - show orientation axes

## Modifying visualization parameters

- This is done through properties panel
- The highlighted button is reminder that the parameters of one or more pipeline object are "out of sync" with the data that you are viewing.
  - Hitting the `Apply` button will **accept** these changes
  - Hitting the `Reset` button **Reset** will revert the options back to the last time they were applied
- **Save parameters button**: saves the current values as default
- **Restore parameters button**: Reset back to factory default
- To copy parameters from one object to another, use the **copy** and **paste parameters buttons**.

