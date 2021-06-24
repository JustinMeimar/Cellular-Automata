import { render } from '@testing-library/react';
import React, { Component } from 'react';
import './cell.css'
import useState from 'react';

class Cell extends Component{
    constructor(state){
        super(state)

        this.state = {
            xpos: null,
            ypos: null,
            life: 0,
            nieghbours: [],
            style: {},
        }
        this.state.xpos = this.props.xpos;
        this.state.ypos = this.props.ypos;

        this.handleClick = this.handleClick.bind(this)
    }

    findNeighbours(){
        var i = -1;
        var j = -1;
        for(i;i<=1;i++){
            var temp = i
            for(j;j<=1;j++){
                console.log(temp);
            //     // console.log(this.state.xpos + i, this.state.ypos+ j);
            };
           
        }
        // console.log(this.state.xpos)

    }

    handleClick(){

        // Changing state

        this.findNeighbours()
        if(this.state.life === 0){
            this.setState({life : 1}, 
                () => {
                console.log(this);
            })
            this.state.style = {
                background: 'rgb(0, 128, 4, 0.693)'
            }
        } else{
            this.setState({life : 0}, 
                () => {
                console.log(this);
            })
            this.state.style = {
                background: 'None'
            }
        }
    }

    render(){
       
        return (
            <div style={this.state.style} onClick={this.handleClick} className="cell">
                <div className="cell-coords">
                    {/* ({this.props.xpos},{this.props.ypos}) */}
                </div>
                <div className="cell-life">
                    {/* {this.state.life}                   */}
                </div>
            </div>
        )
      }

}

export default Cell;