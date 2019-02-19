pipeline {
  agent any
  stages {
    stage('build') {
      steps {
        sh 'cmake .'
        sh 'make'
      }
    }
    stage('test') {
      steps {
        sh './entropy_test --gtest_output="xml:entropy_testresults.xml"'
        junit 'entropy_testresults.xml'
      }
    }
  }
}
