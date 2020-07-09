// https://www.hackerrank.com/challenges/magic-spells/problem
// Accepted


    if(typeid(*spell) == typeid(Fireball)) {
        ((Fireball*)spell)->revealFirepower();
    }
    else if(typeid(*spell) == typeid(Frostbite)) {
        ((Frostbite*)spell)->revealFrostpower();
    }
    else if(typeid(*spell) == typeid(Thunderstorm)) {
        ((Thunderstorm*)spell)->revealThunderpower();
    }
    else if(typeid(*spell) == typeid(Waterbolt)) {
        ((Waterbolt*)spell)->revealWaterpower();
    }
    else {
        string spellName = spell->revealScrollName();
        string spellJournal = SpellJournal::journal;
        // LCS Algorithm
        string &a = spellName, &b = spellJournal;
        vector<vector<int> > dp(a.size() + 1, vector<int>(b.size() + 1));
        for(int i = 1; i <= a.size(); i++) {
            for(int j = 1; j <= b.size(); j++) {
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }
