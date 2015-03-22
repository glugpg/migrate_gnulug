<?php

/**
 * Implements hook_migrate_api().
 */
function migrate_gnulug_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'PerugiaGnulug' => array(
        'title' => t('Perugia GNULug'),
      ),
//        'PerugiaGnulugExtras' => array(
//          'title' => t('Perugia GNULug Extras'),
//        ),
    ),

  );

  return $api;
}

/**
 * Register all D6->D7 migrations.
 *
 * @see https://www.drupal.org/node/1813498
 */
function migrate_gnulug_register_migrations() {
  $common_arguments = array(
    'source_version' => 6,
    'group_name' => 'PerugiaGnulug',
    'source_connection' => 'legacy',
    'source_database' => array(
      'driver' => 'mysql',
      'database' => 'GNULUGPG6',
      'username' => 'drupal6', // Ideally this user has readonly access
      // Best practice: use a variable (defined by setting $conf in settings.php, or
      // with drush vset) for the password rather than exposing it in the code.
      'password' => 'drupal6',
      'host' => 'localhost',
      'prefix' => '',
    ),

    'format_mappings' => array(
      '1' => 'filtered_html',
      '2' => 'full_html',
    ),

  );

  /*
  * import dei ruoli
  */
  $role_arguments = $common_arguments + array(
    'machine_name' => 'Ruoli',
    'description' => t('Import roles'),
    'role_mappings' => array(
      'CapoRedattore' => 'CapoRedattore',
      'Redattore' => 'Redattore',
      'Socio' => 'Socio',
      'Consiglio Direttivo' => 'Consiglio Direttivo',
      'Probiviro' => 'Probiviro',
      'Iscrizioni' => 'Iscrizioni',
      'Visitatore' => 'Visitatore',
      'Socio moroso' => 'Ex Socio',
    ),
  );
  Migration::registerMigration('DrupalRole6Migration', $role_arguments['machine_name'], $role_arguments);

  // The description and the migration machine name are also required arguments,
  // which will be unique for each migration you register.
  $user_arguments = $common_arguments + array(
    'description' => t('Migration of users from Drupal 6'),
    'machine_name' => 'ExUser',
    'class_name' => 'MyUserMigrationClass',
    'role_migration' => 'Ruoli',
    'picture_migration' => 'Picture'
  );

  // We just use the migrate_d2d D6 migration class as-is.
  Migration::registerMigration('MyUserMigrationClass', $user_arguments['machine_name'], $user_arguments);

  /*
   * import delle immagini
   */
  $picture_arguments = $common_arguments + array(
    'machine_name' => 'Picture',
    'description' => t('Import image Drupal 6'),
    'default_uid' => 1,
    'source_dir' => '/home/drupal-6/files/pictures',
    'destination_dir' => 'public://',
  );
  Migration::registerMigration('DrupalPicture6Migration', $picture_arguments['machine_name'], $picture_arguments);

  /*
   * import dei file
   */
  $file_arguments = $common_arguments + array(
    'machine_name' => 'File',
    'description' => t('Import Drupal 6 files'),
    'source_dir' => '/home/drupal-6/files',
    'destination_dir' => 'public://',
  );
  Migration::registerMigration('DrupalFile6Migration', $file_arguments['machine_name'], $file_arguments);

  /*
   * import della tassonomia delle gallerie
   */
  $photo_term_arguments = $common_arguments + array(
    'machine_name' => 'ExPhotoTerm',
    'description' => t('Import Drupal 6 photo terms into media terms'),
    'source_vocabulary' => '5',  // "Photo category" vocabulary
    'destination_vocabulary' => 'galleria_immagini',
  );
  Migration::registerMigration('ExPhotoTermMigration', $photo_term_arguments['machine_name'], $photo_term_arguments);

  /*
   * import della tassonomia delle slides
   */
  $slide_term_arguments = $common_arguments + array(
    'machine_name' => 'ExSlideTerm',
    'description' => t('Import Drupal 6 slide terms into media terms'),
    'source_vocabulary' => '4',  // "Photo category" vocabulary
    'destination_vocabulary' => 'categorie_slides',
  );
  Migration::registerMigration('ExSlideTermMigration', $slide_term_arguments['machine_name'], $slide_term_arguments);

  $node_arguments = $common_arguments + array(
    'user_migration' => 'ExUser',
    'default_uid' => 1,
    'default_language' => 'it',
  );

  /*
   * import degli eventi
   */
  $arguments = $node_arguments + array(
    'description' => t('Migration of Eventi nodes from Drupal 6'),
    'machine_name' => 'ExEventi',
    'source_type' => 'event',
    'destination_type' => 'evento',
  );
  Migration::registerMigration('ExEventiMigration', $arguments['machine_name'], $arguments);

  /*
   * import delle Notizie
   */
  $arguments = $node_arguments + array(
    'description' => t('Migration of Notizia nodes from Drupal 6'),
    'machine_name' => 'ExNews',
    'source_type' => 'story',
    'destination_type' => 'article',
  );
  Migration::registerMigration('ExNewsMigration', $arguments['machine_name'], $arguments);

  /*
   * import degli articoli
   */
  $arguments = $node_arguments + array(
    'description' => t('Migration of Articolo nodes from Drupal 6'),
    'machine_name' => 'ExArticolo',
    'source_type' => 'articolo',
    'destination_type' => 'article',
  );
  Migration::registerMigration('ExArticoloMigration', $arguments['machine_name'], $arguments);

  /*
   * import delle pagine
   */
  $arguments = $node_arguments + array(
    'description' => t('Migration of Pagine nodes from Drupal 6'),
    'machine_name' => 'ExPage',
    'source_type' => 'page',
    'destination_type' => 'page',
  );
  Migration::registerMigration('ExPageMigration', $arguments['machine_name'], $arguments);

  /*
   * import delle immagini per gallerie
   */
  $arguments = $node_arguments + array(
    'description' => t('Migration of Immagini Gallerie nodes from Drupal 6'),
    'machine_name' => 'ExImage',
    'source_type' => 'image',
    'destination_type' => 'immagine',
    'dependencies' => array('ExPhotoTerm'),
  );
  Migration::registerMigration('ExImageMigration', $arguments['machine_name'], $arguments);

  /*
   * import delle slides
   */
  $arguments = $node_arguments + array(
    'description' => t('Migration of Slides nodes from Drupal 6'),
    'machine_name' => 'ExSlides',
    'source_type' => 'slides',
    'destination_type' => 'slide',
    'dependencies' => array('ExSlideTerm'),
  );
  Migration::registerMigration('ExSlidesMigration', $arguments['machine_name'], $arguments);

  /*
   * import delle quote
   */
  $arguments = $node_arguments + array(
    'description' => t('Migration of Quote nodes from Drupal 6'),
    'machine_name' => 'ExQuote',
    'source_type' => 'quota_annuale',
    'destination_type' => 'quota_annuale',
  );
  Migration::registerMigration('ExQuoteMigration', $arguments['machine_name'], $arguments);

  /*
   * import dei verbali
   */
  $arguments = $node_arguments + array(
    'description' => t('Migration of Verbali nodes from Drupal 6'),
    'machine_name' => 'ExVerbali',
    'source_type' => 'verbale',
    'destination_type' => 'verbale',
  );
  Migration::registerMigration('ExVerbaliMigration', $arguments['machine_name'], $arguments);

    /*
   * import dei commenti
   */
//  $comment_arguments = $common_arguments + array(
//    'user_migration' => 'ExUser',
//    'default_uid' => 0,
//  );
//
//  $event_comment_arguments = $comment_arguments + array(
//    'machine_name' => 'ExEventComment',
//    'description' => t('Import Drupal 6 event comments'),
//    'source_type' => 'event',
//    'destination_type' => 'evento',
//    'node_migration' => 'ExEventi',
//  );
//
//  Migration::registerMigration('DrupalComment6Migration',
//    $event_comment_arguments['machine_name'], $event_comment_arguments);
//
//  $news_comment_arguments = $comment_arguments + array(
//    'machine_name' => 'ExNewsComment',
//    'description' => t('Import Drupal 6 news comments'),
//    'source_type' => 'story',
//    'destination_type' => 'notizia',
//    'node_migration' => 'ExNews',
//  );
//
//  Migration::registerMigration('DrupalComment6Migration',
//    $news_comment_arguments['machine_name'], $news_comment_arguments);

  /*
   *  Migrazioni tabelle non standard
   */
//  migrate_gnulug_extras($common_arguments);
}
