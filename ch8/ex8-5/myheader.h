enum {
    MAXBOOKS = 50,  // 保持する最大の冊数
    TITLESIZE = 100, // 題名を入れる文字列領域の大きさ
};

// 外部変数の参照宣言
extern int nbooks;
extern char *books[MAXBOOKS];
extern int prices[MAXBOOKS];

// 関数プロトタイプ
void read_books(void);
void search_books(void);
