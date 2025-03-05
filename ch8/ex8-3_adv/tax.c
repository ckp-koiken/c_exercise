extern double rate;  // main.cに定義宣言されている外部変数を参照

int calctax(int price) {
    return price * rate / 100;
}