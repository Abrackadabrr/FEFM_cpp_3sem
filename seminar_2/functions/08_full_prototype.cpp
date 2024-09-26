int alpha();

int beta();

int main() {
    alpha();
    beta();
    return 0;
}

int alpha() {
    beta();
}

int beta() {
    alpha();
}
