if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
map! <D-v> *
nmap  :w:!./run && diff output.txt ans.txt
nnoremap  l l
nnoremap  h h
xmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
xnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
nmap <C-X><C-E> :w:!./run && diff output.txt ans.txt
vmap <BS> "-d
vmap <D-x> "*d
vmap <D-c> "*y
vmap <D-v> "-d"*P
nmap <D-v> "*P
imap { {}O
cabbr Hash w !g++ -E - | sed "/^\#.*$/d" | tr -d '[:space:]' | md5sum | cut -c-6
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set cindent
set cscopetag
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=tw
set hlsearch
set incsearch
set runtimepath=~/.vim,~/.vim/plugged/vim-typing-practice,/usr/local/share/vim/vimfiles,/usr/local/share/vim/vim91,/usr/local/share/vim/vimfiles/after,~/.vim/after
set shiftwidth=4
set tabstop=4
set wildmenu
" vim: set ft=vim :
