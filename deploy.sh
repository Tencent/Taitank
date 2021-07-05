#!/usr/bin/env sh

set -e

# build static files
npm run docs:build

# cd to released document
cd docs/.vuepress/dist

# deploy to custom domain
echo 'taitank.dev' > CNAME

git init
git add -A
git commit -m 'chore(docs): deploy homepage'

# push to gh-pages
git push -f git@github.com:Tencent/Taitank.git master:gh-pages

cd -