The scope of this project has changed. In fact, it is useful only to specify the work to be done when speaking of generation from **RobotML** models towards *Athena* and *VLE*. The pipe line that was created in order to generate *VLE* code (namely **RobotML** towards *Athena* towards *VLE*) became obsolete due to many reasons:

* We had many problems not understood linked to the use of the text-to-text transformation that rendered impossible correct integration of the complete pipe line
* Acceleo has been considered as too difficult to implement and CEA-LIST decided to change towards xtend. Keeping one transformation in Acceleo (*Athena* to *VLE*) while moving the other to xtend (**RobotML** model to *Athena*) was considered too much work for the small team we are
* the meta-model needed by *VLE* is not exactly the meta-model needed by *Athena* thus there are not natural mappings to be done in order to make it run

It was decided thus to develop the generation using xtend to the *VLE* target completing the existing meta-model of what is needed to let this generation work. The wiki pages in the project present the specification of the two generators knowing that the *Athena* one is the old one written using Acceleo.

* **Athena**: *Athena* is a language defined by Dasssault Aviation in the 2000 in order to allow modelling of problems separated from their implementation. The specification of the generator starts from ... web page.

* **VLE**: *VLE* means Virtual Laboratory Environment and is a executable framework using the DEVS theory in order to represent the modelling of systems. This framework has been developped by INRA in order to help aggregate complex models into one simulation. The specification of the generator starts from https://github.com/RobotML/Athena-VLE/wiki/vleSpecification web page.
