struct node{
    char c;
    
    node *first;
    node *next;
    
    bool flag;
    
    node(char c) : c(c), first(NULL), next(NULL), flag(false){};
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


class WordDictionary {
public:
    /** Initialize your data structure here. */
    node *root;
    
    WordDictionary() {
        root = new node('0');        
    }
    
    void create(string &s, int index, node* from){
        
        if(index == s.size()){
            from->flag = true;
            return;
        }
        
        char c = s[index];
             
        node *tmp, *pre;
        
        bool find;
        
        if(from->first){
            tmp = from->first;
            
            find = false;
            
            while(tmp){
                if(tmp->c == c){
                    find = true;
                    break;
                }
                pre = tmp;
                tmp = tmp->next;
            }
            
            if(!find){
                pre->next = new node(c);
                tmp = pre->next;           
            }         
        }else{
            from->first = new node(c);
            tmp = from->first;
        }
        
        create(s, index + 1, tmp);
    }
    
    bool scan(string &s, int index, node *from){
    
        if(!from) return false;
        
        char c = s[index];

        node *tmp;
        
        bool find = false;
        
        tmp = from;
        
        if(c == '.'){
            while(tmp){
                if(index == s.size() - 1)
                    return tmp->flag;
                else{
                    if(scan(s, index + 1, tmp->first)){
                        return true;
                    }
                }
                tmp = tmp->next;
            }    
        }else{       
            while(tmp){
                if(tmp->c == c){
                    if(index == s.size() - 1)
                        return tmp->flag;
                    else
                        return scan(s, index + 1, tmp->first);
                }
                tmp = tmp->next;
            }        
        }
        
        return false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        create(word, 0, root);  
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return scan(word, 0, root->first);    
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */