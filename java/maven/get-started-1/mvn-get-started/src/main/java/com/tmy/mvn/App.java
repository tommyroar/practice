package com.tmy.mvn;

import org.apache.logging.log4j.Logger;
import org.apache.logging.log4j.LogManager;

public class App 
{

    //local init logger
    private static final Logger logger = LogManager.getLogger(App.class);

    public static void main( String[] args )
    {
        logger.error("ERROR");
        System.out.println( "Hello World!" );
    }
}
