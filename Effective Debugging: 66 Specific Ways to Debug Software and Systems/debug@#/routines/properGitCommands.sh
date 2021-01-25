#!/bin/bash 

# Jagoda "juliagoda" Górska, juliagoda.pl@protonmail.com

# Remember to run the script from the directory itself
# ! It's better to write output to the file with '> results.txt'

# STEPS
# 1. Iterate through array
# 2. Check if iterated file exists (yes - go ahead, no - skip to the next item)
# 3. Check how many times the command appears in file
# 4. Compare the result with the expected one (third value from list)
# 5. Check if the number of detected lines are equal to the expected one (yes - show result, no - show message) 

# TODO
# Escape \"%1\" examples

array=(list1 list2 list3 list4 list5 list6 list7 list8 list9 list10 list11 list12 list13 list14 list15 list16 list17 list18 list19 list20 list21 list22 list23 list24 list25 list26 list27 list28 list29 list30 list31 list32 list33 list34 list35 list36 list37 list38 list39 list40 list41 list42 list43 list44 list45 list46 list47 list48 list49 list50 list51 list52 list53 list54 list55 list56 list57 list58 list59 list60 list61 list62 list63 list64 list65 list66 list67 list68 list69 list70 list71 list72 list73 list74 list75 list76 list77 list78 list79 list80 list81 list82 list83 list84 list85 list86 list87 list88 list89 list90 list91)
list1=("git rev-parse HEAD,GitQlient.pro,1")
list2=("git rev-parse,src/big_widgets/GitQlient.cpp,1")
list3=("origin/,src/branches/BranchTreeWidget.cpp,1")
list4=("diff --git,src/diff/DiffHelper.h,1")
list5=("diff --git a/,src/diff/FullDiffWidget.cpp,1")
list6=("git rev-parse --abbrev-ref HEAD,src/git/GitBase.cpp,1")
list7=("git rev-parse HEAD,src/git/GitBase.cpp,1")
list8=("git branch -a,src/git/GitBranches.cpp,1")
list9=("git rev-list --left-right --count %1%2...%3,src/git/GitBranches.cpp,1")
list10=("git branch %1 %2,src/git/GitBranches.cpp,2")
list11=("git checkout %1,src/git/GitBranches.cpp,1")
list12=("git checkout -b %1 %2,src/git/GitBranches.cpp,1")
list13=("git checkout -b %1,src/git/GitBranches.cpp,2")
list14=("git branch -m %1 %2,src/git/GitBranches.cpp,1")
list15=("git branch -D %1,src/git/GitBranches.cpp,1")
list16=("git push --delete %2 %1,src/git/GitBranches.cpp,1")
list17=("git rev-parse %1,src/git/GitBranches.cpp,1")
list18=("git push --set-upstream origin %1,src/git/GitBranches.cpp,1")
list19=("git branch -vv,src/git/GitBranches.cpp,1")
list20=("git config --get --global user.name,src/git/GitConfig.cpp,1")
list21=("git config --get --global user.email,src/git/GitConfig.cpp,1")
list22=("git config --global %1 \"%2\",src/git/GitConfig.cpp,1")
list23=("git config --local %1 \"%2\",src/git/GitConfig.cpp,1")
list24=("git config --get --local user.name,src/git/GitConfig.cpp,1")
list25=("git config --get --local user.email,src/git/GitConfig.cpp,1")
list26=("git config --local user.name \"%1\",src/git/GitConfig.cpp,1")
list27=("git config --local user.email %1,src/git/GitConfig.cpp,1")
list28=("git clone --progress %1 %2,src/git/GitConfig.cpp,1")
list29=("git init %1,src/git/GitConfig.cpp,1")
list30=("git config --local --list,src/git/GitConfig.cpp,1")
list31=("git config --global --list,src/git/GitConfig.cpp,1")
list32=("git config --get %1,src/git/GitConfig.cpp,1")
list33=("git annotate %1 %2,src/git/GitHistory.cpp,1")
list34=("git log --follow --pretty=%H %1,src/git/GitHistory.cpp,1")
list35=("git diff-tree --no-color -r --patch-with-stat -m,src/git/GitHistory.cpp,1")
list36=("git diff HEAD ,src/git/GitHistory.cpp,1")
list37=("git diff %1 -w -U15000 ,src/git/GitHistory.cpp,1")
list38=("--cached,src/git/GitHistory.cpp,1")
list39=("git diff-tree -C --no-color -r -m ,src/git/GitHistory.cpp,1")
list40=("git add --intent-to-add %1,src/git/GitHistory.cpp,1")
list41=("git diff %1,src/git/GitHistory.cpp,3")
list42=("git reset %1,src/git/GitHistory.cpp,1")
list43=("git add %1,src/git/GitLocal.cpp,1")
list44=("git cherry-pick %1,src/git/GitLocal.cpp,1")
list45=("git cherry-pick --abort,src/git/GitLocal.cpp,1")
list46=("git cherry-pick --continue,src/git/GitLocal.cpp,1")
list47=("git checkout %1,src/git/GitLocal.cpp,2")
list48=("git reset %1,src/git/GitLocal.cpp,1")
list49=("git reset --%1 %2,src/git/GitLocal.cpp,1")
list50=("git commit -m \\/\"%1\\/\",src/git/GitLocal.cpp,1")
list51=("git commit --amend,src/git/GitLocal.cpp,1")
list52=("git rm --cached --ignore-unmatch -- ,src/git/GitLocal.cpp,1")
list53=("git checkout -q %1,src/git/GitMerge.cpp,1")
list54=("git merge -Xignore-all-space ,src/git/GitMerge.cpp,1")
list55=("git merge --abort,src/git/GitMerge.cpp,1")
list56=("git commit --no-edit,src/git/GitMerge.cpp,1")
list57=("git format-patch -1 %1,src/git/GitPatches.cpp,1")
list58=("git am --signof,src/git/GitPatches.cpp,1")
list59=("git apply,src/git/GitPatches.cpp,2")
list60=("git apply --cached %1,src/git/GitPatches.cpp,1")
list61=("git push %1 %2 %3,src/git/GitRemote.cpp,1")
list62=("git push ,src/git/GitRemote.cpp,2")
list63=("--force,src/git/GitRemote.cpp,3")
list64=("git fetch --all --tags --force %1,src/git/GitRemote.cpp,1")
list65=("--prune --prune-tags,src/git/GitRemote.cpp,1")
list66=("git remote prune origin,src/git/GitRemote.cpp,1")
list67=("git rev-parse --show-cdup,src/git/GitRepoLoader.cpp,1")
list68=("git show-ref -d,src/git/GitRepoLoader.cpp,1")
list69=("git log --date-order --no-color --log-size --parents --boundary -z --pretty=format:,src/git/GitRepoLoader.cpp,1")
list70=("git rev-parse --revs-only HEAD,src/git/GitRepoLoader.cpp,1")
list71=("git diff-index %1,src/git/GitRepoLoader.cpp,1")
list72=("git diff-index --cached %1,src/git/GitRepoLoader.cpp,1")
list73=("git ls-files --others,src/git/GitRepoLoader.cpp,1")
list74=(" --exclude-from=$%1,src/git/GitRepoLoader.cpp,1")
list75=(" --exclude-per-directory=$%1$,src/git/GitRepoLoader.cpp,1")
list76=("git stash list,src/git/GitStashes.cpp,1")
list77=("git stash pop,src/git/GitStashes.cpp,1")
list78=("git stash,src/git/GitStashes.cpp,6")
list79=("git stash clear,src/git/GitStashes.cpp,1")
list80=("git stash branch %1 %2,src/git/GitStashes.cpp,1")
list81=("git stash drop -q %1,src/git/GitStashes.cpp,1")
list82=("git config --file .gitmodules --name-only --get-regexp path,src/git/GitSubmodules.cpp,1")
list83=("git submodule add %1 %2,src/git/GitSubmodules.cpp,1")
list84=("git submodule update --init --recursive,src/git/GitSubmodules.cpp,1")
list85=("git ls-remote --tags,src/git/GitTags.cpp,1")
list86=("git push --tags --dry-run,src/git/GitTags.cpp,1")
list87=("git tag -a %1 %2 -m \"%3\",src/git/GitTags.cpp,1")
list88=("git push origin --delete %1,src/git/GitTags.cpp,1")
list89=("git tag -d %1,src/git/GitTags.cpp,1")
list90=("git push origin %1,src/git/GitTags.cpp,1")
list91=("git rev-list -n 1 %1,src/git/GitTags.cpp,1")

fails=0
errorsFile="failures.txt"

rm failures.txt

echo "|   Git command   |   File   |   Results (Line number: found line; line number: found line; etc.)   |"
echo -e "\n"
  
for name in "${array[@]}"; do

  declare -n tuple=$name
  IFS=',' read command file times <<< "$tuple"
  
  file_exists= false
  fullPath="$PWD/../../$file"
  
  if [ -s "$fullPath" ] ; then
    file_exists= true
  else
    file_exists= false
    echo -e "$file file does not exist, or is empty. Skipping\n" >> $errorsFile
    fails=$((fails + 1))
  fi
  
  if $file_exists ; then
    if grep -Rq -- "$command" "$fullPath"
      then
        foundTimes=$(grep -o -- "$command" "$fullPath" | wc -l)
        
        if [ $((times)) -eq $((foundTimes)) ] ; then
        
            line=$(echo "| \"$command\" | $file | Line $(echo -n $(grep -Fn -- "$command" "$fullPath")) |")
            echo $line
            s=$(printf "%-$(echo "${#line}")s" "-")
            echo "${s// /-}"
            
        else
            echo -e "\"$command\" was found in $file $((foundTimes)) times, but should be $times times \n" >> $errorsFile
            fails=$((fails + 1))
        fi
    else
      echo -e "\"$command\" couldn't be found in $file \n" >> $errorsFile
      fails=$((fails + 1))
    fi
  fi
done


if [ $((fails)) -ge 1 ] ; then
  echo -e "\n\n\n"
  echo -e "FAILS: $((fails))\n"
  echo "See \"failures\" file"
fi
