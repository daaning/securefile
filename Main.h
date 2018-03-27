class passkey
{
private:
    int password, key, k;
public:
    passkey();
    void getkey();
    int checkkey(int );
    friend void encrypt(passkey);
    friend void decrypt(passkey);
}file1;
