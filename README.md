The Atomium theme is a Drupal 7 base theme.

The goal of this base theme is to rewrite most of the core themes functions of Drupal and use proper render arrays and
templates instead.
This will allow users to customize at will most of the elements in a custom sub-theme using preprocess functions or by
providing a custom template.

Table of content:
=================
- [Installation](#atomium-installation)
- [Activation](#atomium-activation)
- [Configuration](#atomium-configuration)
- [Contributing](#atomium-contributing)
- [Extending](#atomium-extending)

[Go to top](#table-of-content)

# [Installation](#atomium-installation)
[Download the theme manually](https://www.drupal.org/docs/7/extending-drupal/installing-themes) or using [Drush](https://drupal.org/project/drush).

[Go to top](#table-of-content)

# [Activation](#atomium-activation)
To enable the theme, go to **admin/appearance** and select an Atomium based theme.

Atomium comes with 2 default sub-themes provided as examples.

 - Atomium Bootstrap,
 - Atomium Foundation.
 
Atomium Bootstrap is based on the [Bootstrap framework](https://getbootstrap.com/).
Atomium Foundation is based on the [Zurb Foundation framework](https://foundation.zurb.com/).

These sub-themes are providing examples of *preprocess* functions and templates so you can craft your own theme quickly.

[Go to top](#table-of-content)

# [Configuration](#atomium-configuration)
As Atomium is not intended to be a full featured theme as you might find on drupal.org, full of configurable settings
and with a nice user interface.
The sole purpose of this theme is to provides a clean markup that you can easily extend.

However, Atomium provides the following settings:

 - Enable theme debug,
 - Allow CSS double underscore.
 
As of Drupal 7.33, Drupal core has a theme debug mode that can be enabled and disabled via the
**theme_debug** variable.
Theme debug mode can be used to see possible template suggestions and the locations of template files right in your HTML
markup (as HTML comments).

As of Drupal 7.51, a new **allow_css_double_underscores** variable has been added to allow for double underscores
in CSS identifiers. In order to allow CSS identifiers to contain double underscores (*.example__selector*) for Drupal's
[BEM-style naming standards](http://getbem.com/), this variable can be set to TRUE.

[Go to top](#table-of-content)

# [Contributing](#atomium-contributing)

Atomium is licenced under [EUPL Licence](https://en.wikipedia.org/wiki/European_Union_Public_Licence).
All contribution to Atomium and its sub-themes are made on [Github](https://github.com/ec-europa/atomium), the main
Atomium's repository.

[Go to top](#table-of-content)

# [Extending](#atomium-extending)

Atomium provides a way to extend just by creating some files without modifying the core Atomium files.
Each theme definition, core or custom, are treated as a component.
You can find all the theme definitions in the *templates* directory of each sub-themes.

To create a new theme definition:

 - Create a directory in *templates*, name it as you will, a good practice is to name it the name of the definition.
 - Create a file *[NAME-OF-THE-THEME-DEFINITION].component.inc*,
 - Create the function *[NAME-OF-THE-THEME]\_atomium_theme\_[NAME-OF-THE-THEME-DEFINITION]\()*,
 - Create a file *[NAME-OF-THE-THEME_DEFINITION].css* and/or *[NAME-OF-THE-THEME_DEFINITION].js* to get these files
  automatically loaded.
  
Do not forget to clear the cache every time new theme definitions or process/preprocess are added or removed.

[Go to top](#table-of-content)
