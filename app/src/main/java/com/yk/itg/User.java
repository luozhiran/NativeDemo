package com.yk.itg;

import android.util.Log;

public class User {
    private String name;

    public String getName() {
        Log.e("User","本地方法调用");
        return name;
    }

    public void setName(String name) {
        Log.e("User","本地方法调用---------------------"+name);
        this.name = name;
    }
}
