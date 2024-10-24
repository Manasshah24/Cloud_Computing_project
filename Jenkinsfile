pipeline {
    agent any
    environment {
        DOCKER_CREDENTIALS = credentials('docker-credentials')
    }
    stages {
        stage('Build') {
            steps {
                bat 'copy.bat'
                bat 'docker build -t uc1 ./uc1'
                bat 'docker login -u ${manascloud24} -p ${manasrahul} ${https://index.docker.io/v1/}'
                bat 'docker tag uc1 manascloud24/uc1:latest'
                bat 'docker push manascloud24/uc1:latest'
                bat 'docker build -t uc2 ./uc2'
                bat 'docker tag uc2 manascloud24/uc2:latest'
                bat 'docker push manascloud24/uc2:latest'
                bat 'docker build -t uc3 ./uc3'
                bat 'docker tag uc3 manascloud24/uc3:latest'
                bat 'docker push manascloud24/uc3:latest'
                bat 'docker build -t frontend ./frontend'
                bat 'docker tag frontend manascloud24/frontend:latest'
                bat 'docker push manascloud24/frontend:latest'
            }
        }
        
        stage('Deploy') {
            steps {
                 bat 'kubectl apply -f kubernetes.yaml'
            }
        }
    }
    
    post {
        failure {
            echo 'Pipeline failed'
        }
    }
}
