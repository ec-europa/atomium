const path = require('path');
const copy = require('fs-extra').copy;

const frameworkDir = path.resolve(__dirname, '../node_modules/@ec-europa/europa-component-library/framework');
const dest = path.resolve(__dirname, '../dist');

// Copy fonts
copy(path.resolve(frameworkDir, 'fonts'), path.resolve(dest, 'fonts'), (err) => {
  if (err) {
    return console.error(err);
  }

  return console.log('Fonts copied!');
});

// Copy images
copy(path.resolve(frameworkDir, 'images'), path.resolve(dest, 'images'), (err) => {
  if (err) {
    return console.error(err);
  }

  return console.log('Images copied!');
});

// Copy Tachyons CSS.
copy(path.resolve(path.resolve(__dirname, '../node_modules/tachyons'), 'css'), path.resolve(dest, 'styles'), (err) => {
  if (err) {
    return console.error(err);
  }

  return console.log('Tachyons CSS copied!');
});
