//create on 20210220
//leetcode-最小覆盖子串
//滑动窗口法
class Solution {
public:
    unordered_map<char,int> tnum,subnum; //hashmap，构成字符到整数的映射，保存每个字母出现的次数；和map的区别在于hashmap无序
    //tnum表示字符串t中各个字母出现的字数,sub表示当前滑动窗口内各个字母出现的次数
    //map用法：map[char]如果map里面没有char就输出0，有就输出char出现的次数
    bool check(){
        for(auto i = tnum.begin();i!=tnum.end();i++){
            if(i->second > subnum[i->first]){ //如果t中某个字母出现的次数多余sub内同一字母出现的次数，则t不可能包含sub
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int lent = t.length();
        int lens = s.length();
        if(lens < lent) return ""; //如果t比s长，则s不可能存在子串包含t
        int left = 0,right = lent; //左右指针，左闭右开
        int ans = lens;//记录结果
        int lp = left;//记录结果
        int rp = right;//记录结果
        bool success = false; //记录是否找到
        for(int i=0;i<lent;i++){
            tnum[t[i]]++; //初始化tnum
            subnum[s[i]]++; //初始化滑动窗口[0,,lent)内的subnum
        }
        while(right - left >= lent && right<=lens){
            if(check()){ //如果包含子串
                success = true;
                if(right - left <= ans){ //如果比已求得的子串长度还小，则赋值
                    ans = right - left;
                    lp = left;
                    rp = right;
                }
                left++; //滑动窗口左端向右
                subnum[s[left-1]]--; //除去现在不位于滑动窗口内的字符
                if(ans == lent) break; //子串长度最小为ans
            }
            else{
                right++; //滑动窗口右端向右
                subnum[s[right-1]]++; //新增现在位于滑动窗口内的字符
            }
            //cout<<left<<" "<<right<<endl; //观察两个指针怎么移动
        }
        if(!success) return ""; //left逼近right了
        else{
            return s.substr(lp,rp-lp);
        }

    }
};

/* previous version
class Solution {
public:
    map<char,int> tnum;
    bool check(string s,int left,int right){ //check时间复杂度太高，导致超时
        map<char,int> subnum;
        for(int i=left;i<right;i++){
            subnum[s[i]] ++;
        }
        for(auto i = tnum.begin();i!=tnum.end();i++){
            if(i->second > subnum[i->first]){
                return false;
            }
        }
        
        return true;
    }
    string minWindow(string s, string t) {
        int lent = t.length();
        int lens = s.length();
        if(lens < lent) return "";
        int left = 0,right = lent;
        int ans = lens;
        int lp = left;
        int rp = right;
        bool success = false;
        for(int i=0;i<lent;i++){
            tnum[t[i]] ++;
        }
        while(right - left >= lent && right<=lens){
            if(check(s,left,right)){
                success = true;
                if(right - left <= ans){
                    ans = right - left;
                    lp = left;
                    rp = right;
                }
                left++;
                if(ans == lent) break;
            }
            else right++;
            //cout<<left<<" "<<right<<endl;
        }
        if(!success) return ""; //left逼近right了
        else{
            return s.substr(lp,rp-lp);
        }

    }
};
*/