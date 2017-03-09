/* eslint "import/no-extraneous-dependencies": "off" */
/* eslint "import/extensions": "off" */
import babel from 'rollup-plugin-babel';
import resolve from 'rollup-plugin-node-resolve';
import commonjs from 'rollup-plugin-commonjs';
import uglify from 'rollup-plugin-uglify';

const params = process.env.NODE_ENV === 'production' ? {
  sourceMap: false,
} : {
  sourceMap: 'inline',
};

export default {
  entry: './src/scripts.js',
  dest: 'dist/scripts/europa.js',
  format: 'iife',
  sourceMap: params.sourceMap,
  moduleName: 'Europa',
  exports: 'named',
  plugins: [
    resolve({
      jsnext: true,
      main: true,
      browser: true,
    }),
    commonjs(),
    babel({
      presets: ['es2015-rollup'],
    }),
    (process.env.NODE_ENV === 'production' && uglify()),
  ],
};
