<?php

class ExEventiMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('nid', 'nid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
      $this->addFieldMapping('body:format')
          ->defaultValue('full_html');
      $this->addFieldMapping('field_allegati', 'upload')
          ->sourceMigration('File');
      $this->addFieldMapping('field_allegati:file_class')
          ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_allegati:preserve_files')
          ->defaultValue(TRUE);
      $this->addFieldMapping('field_allegati:description', 'upload:description')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:display', 'upload:list')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:language')
          ->defaultValue(LANGUAGE_NONE);
      // data evento
      $this->addFieldMapping('field_data', 'event_start')
          ->defaultValue('');
      $this->addFieldMapping('field_data:timezone')
          ->defaultValue('Europe/Berlin');
      $this->addFieldMapping('field_data:to', 'event_end')
          ->defaultValue('');
  }

  protected function query() {
    // Get the default query
    $query = parent::query();
    // Add fields from a custom table
    $query->innerJoin('event', 'e', 'n.nid=e.nid');
    $query->fields('e', array('event_start', 'event_end', 'timezone', 'start_in_dst', 'end_in_dst', 'has_time', 'has_end_date'));
    return $query;
  }
}

class ExNewsMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('nid', 'nid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
      $this->addFieldMapping('body:format')
          ->defaultValue('full_html');
      $this->addFieldMapping('field_allegati', 'upload')
          ->sourceMigration('File');
      $this->addFieldMapping('field_allegati:file_class')
          ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_allegati:preserve_files')
          ->defaultValue(TRUE);
      $this->addFieldMapping('field_allegati:description', 'upload:description')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:display', 'upload:list')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:language')
          ->defaultValue(LANGUAGE_NONE);
  }
}

class ExArticoloMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('nid', 'nid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
      $this->addFieldMapping('body:format')
          ->defaultValue('full_html');
      $this->addFieldMapping('field_allegati', 'upload')
          ->sourceMigration('File');
      $this->addFieldMapping('field_allegati:file_class')
          ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_allegati:preserve_files')
          ->defaultValue(TRUE);
      $this->addFieldMapping('field_allegati:description', 'upload:description')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:display', 'upload:list')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:language')
          ->defaultValue(LANGUAGE_NONE);
  }
}

class ExPageMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('nid', 'nid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
      $this->addFieldMapping('language')
           ->defaultValue('it');
      $this->addFieldMapping('body:format')
          ->defaultValue('full_html');
      $this->addFieldMapping('field_allegati', 'upload')
          ->sourceMigration('File');
      $this->addFieldMapping('field_allegati:file_class')
          ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_allegati:preserve_files')
          ->defaultValue(TRUE);
      $this->addFieldMapping('field_allegati:description', 'upload:description')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:display', 'upload:list')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:language')
          ->defaultValue(LANGUAGE_NONE);

      $this->addFieldMapping('field_vista', 'field_vista')
          ->defaultValue('');
      $this->addFieldMapping('field_vista:vargs', 'field_vista:vargs')
          ->defaultValue('');
  }
}

class ExImageMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
//        $this->dependencies[] = 'ExPhotoTerm';

      $this->addFieldMapping('nid', 'nid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
      $this->addFieldMapping('body:format')
          ->defaultValue('full_html');
      // Note that we map migrated terms by the vocabulary ID.
      $this->addFieldMapping('field_galleria_fotografica', '5')
           ->sourceMigration('ExPhotoTerm');
      $this->addFieldMapping('field_galleria_fotografica:source_type')
           ->defaultValue('tid');
      $this->addFieldMapping('field_image', 'fid')
           ->sourceMigration('File');
      $this->addFieldMapping('field_image:file_class')
           ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_image:preserve_files')
          ->defaultValue(TRUE);
      //$this->addFieldMapping('field_image:description', 'upload:description')
          //->defaultValue('');
      //$this->addFieldMapping('field_image:display')
          //->defaultValue('');
      $this->addFieldMapping('field_image:language')
          ->defaultValue(LANGUAGE_NONE);
  }

  /**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
  //public function prepareRow($row) {
    //if (parent::prepareRow($row) === FALSE) {
      //return FALSE;
    //}

    //$image_row = Database::getConnection('default', $this->sourceConnection)
                 //->select('image', 'i')
                 //->fields('i', array('fid'))
                 //->condition('nid', $row->nid)
                 //->execute()
                 //->fetchObject();
    //if ($image_row) {
      //$row->fid = $image_row->fid;
      ////$row->filename = $image_row->filename;
    //}
    //else {
      //$this->saveMessage(t('No custom_image_table data for image node with vid !vid',
                         //array('!vid' => $row->vid)));
    //}
  //}

  protected function query() {
    // Get the default query
    $query = parent::query();
    // Add fields from a custom table
    $query->leftJoin('image', 'im', 'n.nid=im.nid');
    $query->fields('im', array('fid'));
    return $query;
  }
}

class ExSlidesMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('nid', 'nid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
      $this->addFieldMapping('language')
           ->defaultValue('it');
      $this->addFieldMapping('body:format')
          ->defaultValue('full_html');
      $this->addFieldMapping('field_allegati', 'upload')
          ->sourceMigration('File');
      $this->addFieldMapping('field_allegati:file_class')
          ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_allegati:preserve_files')
          ->defaultValue(TRUE);
      $this->addFieldMapping('field_allegati:description', 'upload:description')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:display', 'upload:list')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:language')
          ->defaultValue(LANGUAGE_NONE);

      // Note that we map migrated terms by the vocabulary ID.
      $this->addFieldMapping('field_categoria_slide', '4')
           ->sourceMigration('ExSlideTerm                         ');
      $this->addFieldMapping('field_categoria_slide:source_type')
           ->defaultValue('tid');

      $this->addFieldMapping('field_autore', 'field_autore')
          ->defaultValue('');
      $this->addFieldMapping('field_autore:language')
          ->defaultValue(LANGUAGE_NONE);

      $this->addFieldMapping('field_video_vimeo', 'field_videovimeo_value')
          ->defaultValue('');
      $this->addFieldMapping('field_video_vimeo:language')
          ->defaultValue(LANGUAGE_NONE);

  }

  protected function query() {
    // Get the default query
    $query = parent::query();
    // Add fields from a custom table
    $query->leftJoin('content_field_videovimeo', 'vm', 'f.field_rel_videovimeo_nid=vm.nid');
    $query->fields('vm', array('field_videovimeo_value',));
    return $query;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ($row->field_videovimeo_value) {
      $row->field_videovimeo_value = 'https://vimeo.com/'. $row->field_videovimeo_value;
    }

    //$vimeo_row = Database::getConnection('default', $this->sourceConnection)
                 //->select('content_field_videovimeo', 'vm')
                 //->fields('vm', array('field_videovimeo_value'))
                 //->condition('nid', $row->nid)
                 //->execute()
                 //->fetchObject();
    //if ($vimeo_row) {
      //$row->field_rel_videovimeo = 'https://vimeo.com/'. $vimeo_row->field_videovimeo_value;
    //}
    //else {
      //$this->saveMessage(t('No field_videovimeo_value data for node with vid !vid',
                         //array('!vid' => $row->vid)));
    //}
  }
}

class ExQuoteMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('nid', 'nid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
      $this->addFieldMapping('language')
           ->defaultValue('it');
      $this->addFieldMapping('body:format')
          ->defaultValue('full_html');
      $this->addFieldMapping('field_allegati', 'upload')
          ->sourceMigration('File');
      $this->addFieldMapping('field_allegati:file_class')
          ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_allegati:preserve_files')
          ->defaultValue(TRUE);
      $this->addFieldMapping('field_allegati:description', 'upload:description')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:display', 'upload:list')
          ->defaultValue('');
      $this->addFieldMapping('field_allegati:language')
          ->defaultValue(LANGUAGE_NONE);
      // campi quota
      $this->addFieldMapping('field_importo_quota', 'field_quota_value')
          ->defaultValue(0);
      $this->addFieldMapping('field_data_pagamento', 'field_data_verbale')
          ->defaultValue('');
      $this->addFieldMapping('field_data_pagamento:timezone')
          ->defaultValue('Europe/Berlin');
      $this->addFieldMapping('field_socio_pagante', 'field_usersocio')
          ->defaultValue(0);
      $this->addFieldMapping('field_anno_rif_quota', 'field_quota_anno_rif')
          ->defaultValue('');
      $this->addFieldMapping('field_anno_rif_quota:timezone')
          ->defaultValue('Europe/Berlin');
      $this->addFieldMapping('field_modalita_pagamento', 'field_mod_pagamento')
          ->defaultValue('');
  }
}

class ExVerbaliMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('nid', 'nid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);
      $this->addFieldMapping('language')
           ->defaultValue('it');

      $this->addFieldMapping('field_verbale', 'upload')
          ->sourceMigration('File');
      $this->addFieldMapping('field_verbale:file_class')
          ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_verbale:preserve_files')
          ->defaultValue(TRUE);
      $this->addFieldMapping('field_verbale:description', 'upload:description')
          ->defaultValue('');
      $this->addFieldMapping('field_verbale:display', 'upload:list')
          ->defaultValue('');
      $this->addFieldMapping('field_verbale:language')
          ->defaultValue(LANGUAGE_NONE);

      $this->addFieldMapping('field_data_verbale', 'field_data_verbale')
          ->defaultValue('');
      $this->addFieldMapping('field_data_verbale:timezone')
          ->defaultValue('Europe/Berlin');
  }

  //public function complete($entity, stdClass $row) {
    //db_update('file_managed')
      //->condition('fid', $row->fids, 'IN')
      //->expression('uri', 'REPLACE(uri, "private:", "public:")')
      //->execute();
    //$this->saveMessage(t('file with vid !vid',
                         //array('!vid' => $row->fids)));
  //}
}
