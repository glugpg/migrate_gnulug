<?php

class MyUserMigrationClass extends DrupalUser6Migration {

    public function __construct($arguments) {
        parent::__construct($arguments);

        $this->addFieldMapping('roles', 'roles')
            ->sourceMigration('Ruoli');

        $this->addFieldMapping('uid', 'uid');
        $this->addFieldMapping('is_new')
            ->defaultValue(TRUE);

        // Campi input
        $this->addFieldMapping('field_datanascita', 'profile_datanascita');
        $this->addFieldMapping('field_datanascita:language')->defaultValue(LANGUAGE_NONE);

        $this->addFieldMapping('field_luogonascita', 'profile_luogonascita');
        $this->addFieldMapping('field_luogonascita:language')->defaultValue(LANGUAGE_NONE);

        $this->addFieldMapping('field_codice_fiscale', 'profile_codicefiscale');
        $this->addFieldMapping('field_codice_fiscale:language')->defaultValue(LANGUAGE_NONE);

        $this->addFieldMapping('field_schemaorg_jobtitle', 'profile_professione');
        $this->addFieldMapping('field_schemaorg_jobtitle:language')->defaultValue(LANGUAGE_NONE);

        $this->addFieldMapping('field_titolo_studio', 'profile_titolostudio');
        $this->addFieldMapping('field_titolo_studio:language')->defaultValue(LANGUAGE_NONE);

        $this->addFieldMapping('field_telefono', 'profile_telefono');
        $this->addFieldMapping('field_telefono:language')->defaultValue(LANGUAGE_NONE);


        $this->addFieldMapping('field_indirizzo')->defaultValue('IT');
        $this->addFieldMapping('field_indirizzo:language')->defaultValue(LANGUAGE_NONE);

        $this->addFieldMapping('field_indirizzo:thoroughfare', 'profile_indirizzoresidenza');

        $this->addFieldMapping('field_indirizzo:postal_code', 'profile_capresidenza');

        $this->addFieldMapping('field_indirizzo:locality', 'profile_cittaresidenza');

        $this->addFieldMapping('field_indirizzo:administrative_area', 'profile_provinciaresidenza');

    }
}