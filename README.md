# Atomium
[![Build Status](https://travis-ci.org/ec-europa/atomium.svg?branch=7.x-1.x)](https://travis-ci.org/ec-europa/atomium)

The Atomium theme is a Drupal 7 base theme.

The goal of this base theme is to rewrite most of the core theme functions of
Drupal and use proper render arrays and templates instead.
This will allow users to customize at will most of the elements in a custom
sub-theme using preprocess functions or by providing a custom template.

Table of contents:
=================
- [Installation](#installation)
- [Activation](#activation)
- [Configuration](#configuration)
- [Contributing](#contributing)
- [Extending](#extending)
- [Developers note](#developers-note)
- [Known issues](#known-issues)
- [In the press](#in-the-press)

[Go to top](#table-of-content)

# Installation
[Download the theme manually](https://www.drupal.org/docs/7/extending-drupal/installing-themes) or using [Drush](https://drupal.org/project/drush).

[Go to top](#table-of-content)

# Activation
To enable the theme, go to **admin/appearance** and select an Atomium
based theme.

Atomium comes with 2 default sub-themes provided as examples.

 - Atomium Bootstrap,
 - Atomium Foundation,
 - Atomium Bartik.
 
Atomium Bootstrap is based on the [Bootstrap framework](https://getbootstrap.com/).
Atomium Foundation is based on the [Zurb Foundation framework](https://foundation.zurb.com/).
Atomium Bartik is a fork on the Bartik core theme using the Atomium mechanisms.

These sub-themes provide examples of *preprocess* functions and templates
so you can craft your own theme quickly.

[Go to top](#table-of-content)

# Configuration
Atomium is not intended to be a full featured theme as you might find on
drupal.org, full of configurable settings and with a nice user interface.
The sole purpose of this theme is to provide clean markup that you can
easily extend.

However, Atomium provides the following settings:

 - Enable theme debug mode.
 - Allow CSS double underscore.
 
As of Drupal 7.33, Drupal core has a theme debug mode that can be enabled and
disabled via the **theme_debug** variable.
Theme debug mode can be used to see possible template suggestions and the
locations of template files right in your HTML markup (as HTML comments).

As of Drupal 7.51, a new **allow_css_double_underscores** variable has been
added to allow for double underscores in CSS identifiers. In order to allow
CSS identifiers to contain double underscores (*.example__selector*) for
Drupal's [BEM-style naming standards](http://getbem.com/), this variable
can be set to TRUE.

[Go to top](#table-of-content)

# Contributing

Atomium is licenced under the [EUPL Licence](https://en.wikipedia.org/wiki/European_Union_Public_Licence).
All contributions to Atomium and its sub-themes are made on [Github](https://github.com/ec-europa/atomium), the main
Atomium repository.

To ensure its code quality, Atomium depends on [GrumPHP](https://github.com/phpro/grumphp).

In order to use it and pass the automated tests, run:

`$ composer install`

This will:

  1. Build a target test site in `./build`
  2. Run `$ ./vendor/bin/run drupal:site-setup` which will setup site and tests configuration files, such as `phpunit.xml`

After that:

  1. Copy `runner.yml.dist` into `runner.yml` and customize it according to your local environment
  2. Install the site by running `$ ./vendor/bin/run drupal:site-install`

For a list of available commands run:

```
./vendor/bin/run
```

For more information about how to customise the building process check the [OpenEuropa Task Runner](https://github.com/ec-europa/oe-task-runner)
project page.

The best way to submit code is by providing a pull request on Github.

This also helps us to have the automated tests triggered automatically and save
times on checking code styles.

[Go to top](#table-of-content)

# Extending

Atomium provides a way of extending just by creating some files without modifying
the core Atomium files.
Each theme definition, core or custom, is treated as a component.
You can find all the theme definitions in the *templates* directory of
each sub-theme.

To create a new theme definition:

 - Create a directory in *templates* and name it as you will. A good practice
 is to give it the name of the definition.
 - Create a file *[NAME-OF-THE-THEME-DEFINITION].component.inc*,
 - Create the function *[NAME-OF-THE-THEME]\_atomium_theme\_[NAME-OF-THE-THEME-DEFINITION]\()*,
 - Create a file *[NAME-OF-THE-THEME_DEFINITION].css* and/or *[NAME-OF-THE-THEME_DEFINITION].js* to get these files
  automatically loaded.
  
Atomium provides a custom page available on the path: **atomium-overview**.
This particular page is only available to users with _administer themes_ permission.

This page acts as a showcase page of components.
To add a component in there, your component needs to define two hooks:
 - hook_atomium_definition_hook().
   
   This hook allows you to define simply a component.
 - hook_atomium_definition_form_hook().
   
   This hook allows you to define one or multiple components in a Drupal form.
   
For a better understanding and examples, see the [atomium.api.php](https://github.com/ec-europa/atomium/blob/7.x-1.x/atomium/atomium.api.php) file.
  
Do not forget to clear the cache every time a new theme definition or
process/preprocess is added or removed.

[Go to top](#table-of-content)

# Developer's note

During the development of this project, a lot of time has been put into
analyzing how Drupal's core functions were implemented and how to improve them
for better customization.

A good example of this is the breadcrumb generation.

Let's analyse how it's currently done in Drupal and how we've implemented it.

````php
$variables['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb()));
````

By default, Drupal uses the function *drupal_get_breadcrumb()* in its
*template_process_page()* hook.

The function *drupal_get_breadcrumb()* returns raw HTML.
Thus, it's impossible to alter the breadcrumbs links properly.

In order to get a render array, we have to go deeper and rewrite functions
accordingly.

*drupal_get_breadcrumb()* calls *menu_get_active_breadcrumb()*.
This is actually the function that returns the HTML.

There is no way to alter the result of that function as it returns an array of
raw HTML links.

Unfortunately, in order to change this behaviour, we have to create two extra
functions in Atomium and change the way
the breadcrumb is generated.

````php
  $variables['breadcrumb'] = array(
    '#theme' => array('breadcrumb'),
    '#breadcrumb' => atomium_drupal_get_breadcrumb(),
  );
````

*atomium_drupal_get_breadcrumb()* is an atomium internal function written only
for the breadcrumb handling. Instead of calling *menu_get_active_breadcrumb()*,
it calls *atomium_menu_get_active_breadcrumb()* which is also a
custom Atomium function that, instead of returning an array of raw HTML links,
returns an array of render arrays.

This is why, in *page.tpl.php*, instead of writing:

````php
<?php print $breadcrumb; ?>
````

You have to use:

````php
<?php print render($breadcrumb); ?>
````

The rendering process is at the very end of the Drupal's chain of preprocess,
process and render functions.

[Go to top](#table-of-content)

# Known issues

* Vertical tabs: Unable to apply the theme function call inheritance. It has a link with the process function. 

[Go to top](#table-of-content)


# In the press

* [A word about Atomium](http://not-a-number.io/2017/a-word-about-atomium)

[Go to top](#table-of-content)