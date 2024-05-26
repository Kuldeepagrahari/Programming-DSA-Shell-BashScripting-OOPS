D_Three_Activities
D_Three_Activities
 for ( int i = 0 ; i < n ; i ++ ){
            int d1 = v1[i] - a;
            int d2 = v2[i] - b;
            int d3 = v3[i] - c;

            if ( d1 > d2 && d1 > d3 ){
                a = v1[i];
            }
            else if ( d2 > d1 && d2 > d3 ){
                b = v2[i];
            }
            else {
                c = v3[i];
            }
            cout << a << " " << b << " " << c << endl;
        }