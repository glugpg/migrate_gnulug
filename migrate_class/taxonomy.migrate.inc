<?php

class ExPhotoTermMigration extends DrupalTerm6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('tid', 'tid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);

  }

  public function preImport() {
    parent::preImport();
    $vocabs = taxonomy_vocabulary_get_names();
    $vid = $vocabs[$this->destination->getBundle()]->vid;
    $query = $this->query(); // $this->termsQuery is set to the $query that I submitted as my source sql
    if ($this->getItemLimit()>0) {
      $query->range(0, $this->getItemLimit());
    }
    $results = $query->execute()->fetchAllAssoc('tid');
    foreach ($results as $tid=>$result) {
      if (!taxonomy_term_load($tid)) {
        $term = new StdClass();
        $term->tid = $tid;
        $term->name = 'Stub term: ' . $tid;
        $term->description = '';
        $term->vid = $vid;
        $status = drupal_write_record('taxonomy_term_data', $term);
      }
    }
  }

  public function postImport() {
    parent::postImport();
    cache_clear_all('*', 'cache_entity_taxonomy_term', TRUE);
  }
}

class ExSlideTermMigration extends DrupalTerm6Migration {
  public function __construct(array $arguments) {
      parent::__construct($arguments);
        //$this->dependencies[] = 'ExCategories';

      $this->addFieldMapping('tid', 'tid');
      $this->addFieldMapping('is_new')
          ->defaultValue(TRUE);

  }

  public function preImport() {
    parent::preImport();
    $vocabs = taxonomy_vocabulary_get_names();
    $vid = $vocabs[$this->destination->getBundle()]->vid;
    $query = $this->query(); // $this->termsQuery is set to the $query that I submitted as my source sql
    if ($this->getItemLimit()>0) {
      $query->range(0, $this->getItemLimit());
    }
    $results = $query->execute()->fetchAllAssoc('tid');
    foreach ($results as $tid=>$result) {
      if (!taxonomy_term_load($tid)) {
        $term = new StdClass();
        $term->tid = $tid;
        $term->name = 'Stub term: ' . $tid;
        $term->description = '';
        $term->vid = $vid;
        $status = drupal_write_record('taxonomy_term_data', $term);
      }
    }
  }

  public function postImport() {
    parent::postImport();
    cache_clear_all('*', 'cache_entity_taxonomy_term', TRUE);
  }
}
