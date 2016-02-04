#!/bin/bash
mvn archetype:generate -DarchetypeCatalog=http://struts.apache.org/ -DgroupId=com.tmy.struts -DartifactId=struts-1 -DarchetypeGroupId=org.apache.struts -DarchetypeArtifactId=struts2-archetype-starter -DarchetypeVersion=2.3.24.1 -DremoteRepositories=http://struts.apache.org
