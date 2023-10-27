function git_branch {
  branch="`git branch 2>/dev/null | grep "^\*" | sed -e "s/^\*\ //"`"
  if [ "${branch}" != "" ];then
      if [ "${branch}" = "(no branch)" ];then
          branch="(`git rev-parse --short HEAD`...)"
      fi
      echo "（$branch）"
  fi
}

#export PS1="\u@\w\a (git) "
export PS1='\[\e[37;40m\][\[\033[01;36m\]\u\[\e[37;40m\]@\[\e[0m\]\h \[\033[01;36m\]\W\[\033[01;32m\]$(git_branch)\[\033[00m\]\[\e[37;40m\]]\[\e[0m\]\$ '
