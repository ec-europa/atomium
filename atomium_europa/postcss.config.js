const params = process.env.NODE_ENV === 'production' ? {
  plugins: [
    'cssnano',
  ],
  map: 'file',
} : {
  plugins: [
    'autoprefixer',
  ],
  map: true,
};

module.exports = {
  use: params.plugins,
  output: 'dist/styles/europa.css',
  map: params.map,
};
