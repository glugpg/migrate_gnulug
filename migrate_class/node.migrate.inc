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

      //$this->addFieldMapping('field_image', 'fid')
          //->sourceMigration('File');
      //$this->addFieldMapping('field_image:file_class', 'fid')
          //->defaultValue('MigrateFileFid');
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
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $image_row = Database::getConnection('default', $this->sourceConnection)
                 ->select('image', 'i')
                 ->fields('i', array('fid'))
                 ->condition('nid', $row->nid)
                 ->execute()
                 ->fetchObject();
    if ($image_row) {
      $row->fid = $image_row->fid;
      //$row->filename = $image_row->filename;
    }
    else {
      $this->saveMessage(t('No custom_image_table data for image node with vid !vid',
                         array('!vid' => $row->vid)));
    }
  }

//  protected function query() {
//    // Get the default query
//    $query = parent::query();
//    // Add fields from a custom table
//    $query->innerJoin('image', 'i', 'n.nid=i.nid');
//    $query->fields('i', array('fid',));
//    return $query;
//  }
}